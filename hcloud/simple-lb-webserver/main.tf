variable "hcloud_token" {
  description = "Hetzner Cloud Read/Write API token"
}

terraform {
  required_providers {
    hcloud = {
      source  = "hetznercloud/hcloud"
      version = "1.45.0"
    }
  }
}

provider "hcloud" {
  token = var.hcloud_token
}

locals {
  location     = "nbg1"
  server_count = 5
}

# ---

resource "hcloud_network" "network" {
  name     = "network"
  ip_range = "10.0.0.0/16"
}

resource "hcloud_network_subnet" "network-subnet" {
  type         = "cloud"
  network_id   = hcloud_network.network.id
  network_zone = "eu-central"
  ip_range     = "10.0.1.0/24"
}

resource "hcloud_server" "server" {
  count = local.server_count

  name        = "server-${count.index}"
  server_type = "cx11"
  image       = "ubuntu-22.04"
  location    = local.location
  user_data   = file("${path.module}/vm_cloud_init_config.yaml")

  network {
    network_id = hcloud_network.network.id
    ip         = "10.0.1.${10 + count.index}"
  }
  public_net {
    ipv4_enabled = true # needed for apt to fetch packages and updates
    ipv6_enabled = false
  }

  # **Note**: the depends_on is important when directly attaching the
  # server to a network. Otherwise Terraform will attempt to create
  # server and sub-network in parallel. This may result in the server
  # creation failing randomly.
  depends_on = [
    hcloud_network_subnet.network-subnet
  ]
}

resource "hcloud_load_balancer" "load_balancer" {
  name               = "my-load-balancer"
  load_balancer_type = "lb11"
  location           = local.location
  algorithm {
    type = "round_robin" # round_robin, least_connections
  }
}

resource "hcloud_load_balancer_network" "network" {
  load_balancer_id = hcloud_load_balancer.load_balancer.id
  network_id       = hcloud_network.network.id
  ip               = "10.0.1.1"
}

resource "hcloud_load_balancer_target" "load_balancer_target" {
  count            = local.server_count
  type             = "server"
  load_balancer_id = hcloud_load_balancer.load_balancer.id
  server_id        = hcloud_server.server[count.index].id
  use_private_ip   = true
}

resource "hcloud_load_balancer_service" "load_balancer_service" {
  load_balancer_id = hcloud_load_balancer.load_balancer.id
  protocol         = "http"

  http {
    sticky_sessions = false # we don't want that here otherwise we would not get responses by different servers
  }

  #   health_check {
  #     protocol = "http"
  #     port     = 80
  #     interval = 10
  #     timeout  = 5

  #     http {
  #       path         = "/"
  #       response     = "OK"
  #       tls          = false
  #       status_codes = ["200"]
  #     }
  #   }
}

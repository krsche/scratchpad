# Simple Example of a LoadBalancer and Webservers

Deploys a level-4 loadbalancer with several webservers as targets.
Accessing the public IP of the LB in the browser shows a website served from different backend servers and their IPs.  

1. Deploy via:

    ```bash
    export HCLOUD_TOKEN=... # generated via webui in hetzner project
    terraform apply -var "hcloud_token=$HCLOUD_TOKEN"
    ```

2. Get the public IP-Address of the Loadbalancer and paste it into your browser.
    (Ensure using _http://_ and not _https://_)
3. Keep refreshing the page and observer the different hostnames :)
4. After you're done playing around
   1. Destroy the resources via `terraform destroy -var "hcloud_token=$HCLOUD_TOKEN"`
   2. Delete the API Key from your Hetzner Cloud Project

## Architecture

```mermaid
flowchart LR

subgraph net [Private Network]
    subgraph server1 [Server 1]
        PrivateIP1[Private IP] ==> s1apache2[Apache2]
    end
    subgraph server2 [Server 2]
        PrivateIP2[Private IP] ==> s2apache2[Apache2]
    end
    subgraph servern [Server n]
        PrivateIPn[Private IP] ==> snapache2[Apache2]
    end

end

Internet ==> LoadBalancer[Load Balancer]

LoadBalancer == :80 ==> PrivateIP1
LoadBalancer == :80 ==> PrivateIP2
LoadBalancer == :80 ==> PrivateIPn
```

---

```mermaid
flowchart LR

subgraph net [Private Network]
    subgraph server1 [Server 1]
        apt1[apt install apache2] --> PublicIP1
    end
    subgraph server2 [Server 2]
        apt2[apt install apache2] --> PublicIP2
    end
    subgraph servern [Server n]
        aptn[apt install apache2] --> PublicIPn
    end

end
    PublicIP1[Public IP] --> Firewall
    PublicIP2[Public IP] --> Firewall
    PublicIPn[Public IP] --> Firewall

Internet -. blocked .-x Firewall

Firewall -- allowed --> Internet
```

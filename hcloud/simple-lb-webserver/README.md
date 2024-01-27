# Simple Example of a LoadBalancer and Webservers

Deploys a level-4 loadbalancer with several webservers as targets.
Accessing the public IP of the LB in the browser shows a website served from different backend servers and their IPs.  

Deploy via:

```bash
export HCLOUD_TOKEN=... # generated via webui in hetzner project
terraform apply -var "hcloud_token=$HCLOUD_TOKEN"
```

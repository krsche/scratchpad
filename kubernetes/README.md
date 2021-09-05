# Kubernetes: Getting Started

## Required Tools
This guide assumes the following tools are available. Install instructions can be found on https://github.com/krsche/install  
- kubectl
- k9s (_optional_)
- helm
- kind



## Getting Started
Create a cluster and deploy one app:  
```bash
# find tag of latest version here: https://hub.docker.com/r/kindest/node/tags?page=1&ordering=last_updated
kind create cluster --name demo --image kindest/node:v1.21.1
```

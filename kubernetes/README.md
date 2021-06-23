# Kubernetes: Getting Started

## Tools
### kubectl
Install `kubectl` using:
```bash
VERSION="1.21.0"
mkdir /tmp/kubectl_$VERSION 
cd /tmp/kubectl_$VERSION
curl -LO https://dl.k8s.io/release/v$VERSION/bin/linux/amd64/kubectl
chmod +x kubectl
sudo mv kubectl /usr/bin/kubectl_$VERSION
sudo ln -s /usr/bin/kubectl_$VERSION /usr/bin/kubectl
```

### k9s
Install `k9s` using:
```bash
VERSION="0.24.10"
mkdir /tmp/k9s_$VERSION
cd /tmp/k9s_$VERSION
wget https://github.com/derailed/k9s/releases/download/v$VERSION/k9s_v${VERSION}_Linux_x86_64.tar.gz
tar -xzf k9s_v${VERSION}_Linux_x86_64.tar.gz
chmod +x k9s
sudo mv k9s /usr/bin/k9s_$VERSION
sudo ln -s /usr/bin/k9s_$VERSION /usr/bin/k9s
```

### helm
Install `helm` using:
```bash
VERSION="3.6.1"
mkdir /tmp/helm_$VERSION
cd /tmp/helm_$VERSION
wget https://get.helm.sh/helm-v$VERSION-linux-amd64.tar.gz
tar -xzf helm-v$VERSION-linux-amd64.tar.gz
chmod +x linux-amd64/helm
sudo mv linux-amd64/helm /usr/bin/helm_$VERSION
sudo ln -s /usr/bin/helm_$VERSION /usr/bin/helm
```

### kind
Install `kind` using:
Install `kind` using:  
```bash
curl -Lo ./kind https://kind.sigs.k8s.io/dl/v0.11.1/kind-linux-amd64
chmod +x ./kind
mv ./kind /usr/bin/kind
```

## Getting Started
Create a cluster and deploy one app:  
```bash
# find tag of latest version here: https://hub.docker.com/r/kindest/node/tags?page=1&ordering=last_updated
kind create cluster --name helm --image kindest/node:v1.21.1
```

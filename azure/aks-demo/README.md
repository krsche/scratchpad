# Some Azure stuff

```bash
az login
az account list
az account set --subscription
```

## AKS
__Resources:__  
- [Quickstart](https://docs.microsoft.com/en-us/azure/aks/kubernetes-walkthrough)
- [MSIs](https://docs.microsoft.com/en-us/azure/aks/use-managed-identity)

__Create Cluster:__  
```bash
RG=scratchpad-aks

az group create --name $RG --location westeurope
az aks create -g $RG -n aks-msi --enable-managed-identity

az aks get-credentials -g $RG -n aks-msi
```

__Deploy App:__  
Using manifests from `./manifests-demo-app`
```bash
kubectl apply -n default -f manifests-demo-app

# check service for external ip (takes a bit until avail.)
kubectl get service azure-vote-front --watch

# Get loading time of homepage
curl -w "%{time_total}s\n" -o /dev/null -s "http://20.76.244.111"

# generate a bit of load on the server
watch -n 0.1 curl -w "%{time_total}s\n" -o /dev/null -s "http://20.76.244.111"
```

__+ Add custom ACR:__  
```bash
# name needs to be globally unique
az acr create -g $RG -n krscheScratchpadAcr --sku Basic
az aks update -g $RG -n aks-msi --attach-acr krscheScratchpadAcr

# login, pull, tag and upload image
# (use lowercase letters in urls, otherwise auth fails)
az acr login -n krschescratchpadacr
az acr repository list -n krschescratchpadacr -o table
docker pull mcr.microsoft.com/azuredocs/azure-vote-front:v1
docker tag mcr.microsoft.com/azuredocs/azure-vote-front:v1 krschescratchpadacr.azurecr.io/azuredocs/azure-vote-front:v1
docker push krschescratchpadacr.azurecr.io/azuredocs/azure-vote-front:v1
az acr repository list -n krschescratchpadacr -o table

# update manifests on aks
cat ./manifests-demo-app/web-deployment.yaml | sed -e 's/mcr.microsoft.com/krschescratchpadacr.azurecr.io/g' | kubectl apply -f -
```

__Delete Everything:__  
```bash
az group delete --name $RG --yes --no-wait
```
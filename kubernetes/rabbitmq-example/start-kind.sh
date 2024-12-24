#!/bin/bash
set -eou pipefail

kind delete cluster -n rgw2
# kind create cluster --config kind-config.yaml
kind create cluster --name rgw2 --image kindest/node:v1.24.7 --config kind-config.yaml

# setup ingress (nginx)
kubectl apply -f https://raw.githubusercontent.com/kubernetes/ingress-nginx/main/deploy/static/provider/kind/deploy.yaml
sleep 5s
kubectl wait --namespace ingress-nginx \
  --for=condition=ready pod \
  --selector=app.kubernetes.io/component=controller \
  --timeout=90s

# install helm charts
helm install rabbitmq ./rabbitmq-chart
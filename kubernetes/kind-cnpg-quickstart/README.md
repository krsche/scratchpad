# CloudNativePostgres (CNPG) Quickstart

For detailled instructions please refer to the Quickstart Guide in the [official docs](https://cloudnative-pg.io/documentation/current/quickstart).

This guide provisions a local k8s cluster using kind, then:

- installs the cnpg operator
- provisions a cnpg cluster, without metrics
- installs the kube-prometheus operator
- provisions a cnpg cluster, with metrics
- adds a prometheus rule

## Kind Cluster & CNPG Operator

```bash
kind create cluster --name pg

helm repo add cnpg https://cloudnative-pg.github.io/charts
helm upgrade --install cnpg --namespace cnpg-system --create-namespace cnpg/cloudnative-pg

kubectl apply -f cluster-example.yaml
```

## Add Kube-Prometheus Operator (for Grafana & Prometheus)

```bash
helm repo add prometheus-community https://prometheus-community.github.io/helm-charts
helm upgrade --install -f ./kube-stack-config.yaml prometheus-community prometheus-community/kube-prometheus-stack

kubectl apply -f cluster-example-with-metrics.yaml
kubectl apply -f prometheus-rules.yaml

# run the following commands in a new terminal
kubectl port-forward service/prometheus-community-grafana 3000:3000
kubectl port-forward service/prometheus-community-kube-prometheus 9090:9090
```

- Grafana
  - Access [Grafana](localhost:3000) with username `admin` and password `prom-operator`
  - Then import a dashboard through the web-ui from the json configuration in `grafana-dashboard.json`
- Prometheus
  - Access [Prometheus](localhost:9090) and look for metrics starting with cnpg & alerts (can take a little bit until shown)

## Connect to the Postgres Database

```bash
# Port forward in a new terminal
SERVICE_NAME=cluster-with-metrics-rw
kubectl port-forward service/$SERVICE_NAME 5432:5432

# list decoded content of the entire secret created by the cnpg operator
SECRET_NAME=cluster-with-metrics-superuser
kubectl get secret $SECRET_NAME -o go-template='{{range $k,$v := .data}}{{printf "%s: " $k}}{{if not $v}}{{$v}}{{else}}{{$v | base64decode}}{{end}}{{"\n"}}{{end}}'

# get only the decoded URI
# + remove the /* database selector
# + replace service name with localhost
# + store for later
PG_SUPERUSER_URI=`kubectl get secret $SECRET_NAME --template={{.data.uri}} | base64 -d | sed 's:/\*::g' | sed -e "s/$SERVICE_NAME/localhost/g"`

# Connect using psql (install with your pkg manager)
#
# Due to this bug https://github.com/kubernetes/kubectl/issues/1169 the ?sslmode=disable is required when running this example with kind. 
# Otherwise the connection drops after the first connect.
psql "${PG_SUPERUSER_URI}?sslmode=disable"
```

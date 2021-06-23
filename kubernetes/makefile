build:
	docker build -t scratchpad-kubernetes-demo:latest .
run:
	docker run --rm scratchpad-kubernetes-demo:latest

cluster:
	kind create

deployment-demo:
	kubectl apply -f minimal_deployment_demo.yml

deployment-nginx:	
	kubectl apply -f minimal_deployment_nginx.yml

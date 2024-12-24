FROM ubuntu:20.04

RUN DEBIAN_FRONTEND=noninteractive && apt-get update && apt-get install -qq -y nginx libnginx-mod-rtmp

COPY nginx.conf /etc/nginx/nginx.conf
EXPOSE 1935

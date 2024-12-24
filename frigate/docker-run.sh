#!/bin/bash

set -e

SCRIPTPATH="$( cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"

docker run -it \
  --name frigate \
  --mount type=tmpfs,target=/tmp/cache,tmpfs-size=1000000000 \
  --shm-size=64m \
  -v $SCRIPTPATH/storage:/media/frigate \
  -v $SCRIPTPATH/config:/config \
  -v /etc/localtime:/etc/localtime:ro \
  -e FRIGATE_RTSP_PASSWORD='password' \
  -p 5001:5000 \
  -p 8554:8554 \
  -p 8555:8555/tcp \
  -p 8555:8555/udp \
  ghcr.io/blakeblackshear/frigate:stable

echo frigate container started with name 'frigate'.
echo To stop the container, run:    docker stop frigate
echo To remove the container, run:  docker rm frigate

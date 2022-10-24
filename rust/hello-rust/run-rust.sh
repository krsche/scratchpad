#!/bin/bash

set -eou pipefail

SCRIPTPATH="$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )"
docker run --rm -e USER=$USER --user "$(id -u)":"$(id -g)" -v "$SCRIPTPATH":/usr/src/myapp -w /usr/src/myapp rust:1.64 "$@"

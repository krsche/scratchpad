# [Choice] Ubuntu version (use hirsuite or bionic on local arm64/Apple Silicon): hirsute, focal, bionic
ARG VARIANT=focal
FROM mcr.microsoft.com/vscode/devcontainers/base:${VARIANT}

# [Optional] Uncomment this section to install additional OS packages.
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    unzip

# Terraform
ENV VERSION 1.0.5
ENV SHA256SUM 7ce24478859ab7ca0ba4d8c9c12bb345f52e8efdc42fa3ef9dd30033dbf4b561

RUN wget "https://releases.hashicorp.com/terraform/$VERSION/terraform_${VERSION}_linux_amd64.zip" -O /tmp/bin.zip
RUN echo "$SHA256SUM  /tmp/bin.zip" | sha256sum -c && \
    mkdir /tools && \
    unzip /tmp/bin.zip -d /usr/local/bin


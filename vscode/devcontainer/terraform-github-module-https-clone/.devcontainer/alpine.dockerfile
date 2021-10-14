FROM alpine:3.13 as builder

RUN apk add --update --no-cache \
        unzip

ENV VERSION 1.0.5
ENV SHA256SUM 7ce24478859ab7ca0ba4d8c9c12bb345f52e8efdc42fa3ef9dd30033dbf4b561

RUN wget "https://releases.hashicorp.com/terraform/$VERSION/terraform_${VERSION}_linux_amd64.zip" -O /tmp/bin.zip
RUN echo "$SHA256SUM  /tmp/bin.zip" | sha256sum -c && \
    mkdir /tools && \
    unzip /tmp/bin.zip -d /tools/


# # Runtime image
# # -------------------------------------
FROM mcr.microsoft.com/azure-cli:2.27.1

COPY --from=builder /tools/* /usr/local/bin

ENTRYPOINT [ "terraform" ]
CMD [ "--help" ]
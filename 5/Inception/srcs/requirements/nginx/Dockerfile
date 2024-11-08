# https://hub.docker.com/_/alpine (version 3.20)
FROM alpine:3.20  

# https://pkgs.alpinelinux.org/packages (nginx, openssl)
RUN apk update && apk add nginx openssl gettext curl

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY conf/default.conf.template /etc/nginx/conf.d/default.conf.template
COPY tools/entrypoint.sh /entrypoint.sh

RUN chmod 777 /entrypoint.sh

ENTRYPOINT ["sh", "/entrypoint.sh"]

# https://hub.docker.com/_/alpine (version 3.20)
FROM alpine:3.20  

# https://pkgs.alpinelinux.org/packages (mariadb)
RUN apk update && apk add mariadb mariadb-client openrc gettext

COPY conf/my.cnf /etc/mysql/my.cnf
COPY tools/entrypoint.sh /entrypoint.sh
COPY tools/init.sql.template /docker-entrypoint-initdb.d/init.sql.template

RUN chmod 644 /etc/mysql/my.cnf
RUN chmod +x /entrypoint.sh

ENTRYPOINT ["sh", "/entrypoint.sh"]
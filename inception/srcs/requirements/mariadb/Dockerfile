FROM alpine:3.14

RUN apk update && apk add mariadb mariadb-client openrc

COPY ./conf/my.cnf /etc/mysql/my.cnf
COPY ./tools/create_users.sql /docker-entrypoint-initdb.d/

RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql && \
    mkdir -p /run/mysqld && \
    chown -R mysql:mysql /run/mysqld /var/lib/mysql /etc/mysql /docker-entrypoint-initdb.d/

EXPOSE 3306

CMD ["mysqld"]
# https://hub.docker.com/_/alpine (version 3.20)
FROM alpine:3.20  

RUN apk update && apk add wget gettext mariadb-client php php-fpm php-opcache php-gd php-mysqli php-zlib php-curl php-mbstring php-json php-session php-xml php-simplexml php-xmlreader php-xmlwriter php-tokenizer php-ctype php-dom php-phar curl

RUN mkdir -p /etc/php83/php-fpm.d \
    && chmod 777 /etc/php83/php-fpm.d
COPY tools/entrypoint.sh /entrypoint.sh
COPY tools/setup.sh /setup.sh
COPY conf/www.conf /etc/php83/php-fpm.d/www.conf

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && mkdir -p /usr/local/bin \
    && mv wp-cli.phar /usr/local/bin/wp-cli.phar

RUN chmod -R 777 /usr/local/bin
RUN chmod 777 /entrypoint.sh /setup.sh

ENTRYPOINT ["sh", "/entrypoint.sh"]
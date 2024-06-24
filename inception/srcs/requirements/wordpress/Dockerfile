FROM alpine:3.14

RUN apk update && apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session

RUN mkdir -p /run/php-fpm7 && \
    sed -i "s/;daemonize = yes/daemonize = no/g" /etc/php7/php-fpm.conf && \
    sed -i "s/;cgi.fix_pathinfo=1/cgi.fix_pathinfo=0/g" /etc/php7/php.ini

COPY ./conf/www.conf /etc/php7/php-fpm.d/www.conf

RUN mkdir -p /var/www/html && \
    chown -R root:root /var/www/html && \
    chmod -R 777 /var/www/html

COPY ./conf/wp-config.php /var/www/html/wp-config.php
RUN ls -la /var/www/html

RUN wget https://wordpress.org/latest.tar.gz -O wordpress.tar.gz && \
    mkdir -p /tmp/wordpress /var/www/html && \
    tar -xzvf wordpress.tar.gz -C /tmp/wordpress --strip-components=1 && \
    cp -r /tmp/wordpress/* /var/www/html && \
    rm -rf /tmp/wordpress && \
    rm wordpress.tar.gz

EXPOSE 9000

CMD ["php-fpm7", "-F"]

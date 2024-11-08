#!/bin/sh
set -e

if [ ! -f /var/www/html/wp-config.php ]; then
    echo "Downloading WordPress core files..."
    wp-cli.phar core download --path=/var/www/html --allow-root --version=6.5 --locale=en_US
    chmod -R 777 /var/www/html

    echo "Creating wp-config.php..."
    wp-cli.phar config create --dbname=${MYSQL_DATABASE} \
                             --dbuser=${MYSQL_USER} \
                             --dbpass=${MYSQL_PASSWORD} \
                             --dbhost=mariadb \
                             --path=/var/www/html \
                             --allow-root \
                             --locale=en_US \
                             --extra-php <<PHP
define( 'WP_DEBUG', true );
define( 'WP_DEBUG_LOG', true );
define( 'WP_DEBUG_DISPLAY', false );
define( 'FS_METHOD', 'direct' );
define( 'WP_MEMORY_LIMIT', '256M' );
PHP
    chmod 777 /var/www/html/wp-config.php
fi

# Run WordPress CLI installation if necessary
if ! wp-cli.phar core is-installed --allow-root --path=/var/www/html; then
    echo "Installing WordPress..."
    wp-cli.phar core install --url=${DOMAIN_NAME} --title="${WORDPRESS_TITLE}" --admin_user=${WORDPRESS_ADMIN_USER} --admin_password=${WORDPRESS_ADMIN_PASSWORD} --admin_email=${WORDPRESS_ADMIN_EMAIL} --allow-root --path=/var/www/html
    wp-cli.phar user create ${WORDPRESS_USER} ${WORDPRESS_USER_EMAIL} --role=editor --user_pass=${WORDPRESS_USER_PASSWORD} --allow-root --path=/var/www/html
    wp-cli.phar plugin install classic-editor --activate --allow-root --path=/var/www/html
fi

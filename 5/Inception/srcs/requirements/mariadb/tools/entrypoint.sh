#!/bin/bash
set -e

# Create necessary directories if they don't exist
mkdir -p /run/mysqld
chmod -R 777 /run/mysqld

# Initialize the database if necessary
if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

# Replace environment variables in init.sql template
envsubst < /docker-entrypoint-initdb.d/init.sql.template > /docker-entrypoint-initdb.d/init.sql

# Run the original entrypoint script for MariaDB
exec /usr/bin/mysqld --user=mysql --datadir=/var/lib/mysql --init-file=/docker-entrypoint-initdb.d/init.sql --port=3306 

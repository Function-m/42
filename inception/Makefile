include srcs/.env

all: certs setup_permissions build up

certs:
	@mkdir -p ${DATA_PATH_HOST}/certs
	@openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
		-keyout ${DATA_PATH_HOST}/certs/server.key \
		-out ${DATA_PATH_HOST}/certs/server.crt \
		-subj "/C=US/ST=State/L=Locality/O=Organization/OU=Unit/CN=${DOMAIN_NAME}"

setup_permissions:
	@mkdir -p ${DATA_PATH_HOST}/mariadb ${DATA_PATH_HOST}/wordpress /var/lib/mysql
	@sudo chown -R 999:999 ${DATA_PATH_HOST}/mariadb || { echo "Failed to set permissions for MariaDB data directory"; exit 1; }
	@sudo chmod -R 777 ${DATA_PATH_HOST}/mariadb
	@sudo chown -R www-data:www-data ${DATA_PATH_HOST}/wordpress || { echo "Failed to set permissions for WordPress data directory"; exit 1; }
	@sudo chmod -R 777 ${DATA_PATH_HOST}/wordpress
	@sudo chown -R 999:999 /var/lib/mysql || { echo "Failed to set permissions for /var/lib/mysql"; exit 1; }
	@sudo chmod -R 777 /var/lib/mysql || { echo "Failed to set permissions for /var/lib/mysql"; exit 1; }
	@echo "Permissions set for MariaDB and WordPress data directories"

build:
	docker-compose -f srcs/docker-compose.yml build --no-cache

up:
	docker-compose -f srcs/docker-compose.yml up -d

down:
	docker-compose -f srcs/docker-compose.yml down

clean:
	docker-compose -f srcs/docker-compose.yml down -v --rmi all
	rm -rf ${DATA_PATH_HOST}/certs

re: clean all
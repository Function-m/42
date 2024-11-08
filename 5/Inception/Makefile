all: up

# Start the containers in detached mode
up:
	@docker-compose -f srcs/docker-compose.yml up -d
	@sleep 5
	@docker ps

# Stop the containers
down:
	@docker-compose -f srcs/docker-compose.yml down

# Display logs from the containers
logs:
	@echo "Nginx"
	@docker exec -it nginx /bin/sh -c "cat /var/log/nginx/error.log"
	@echo "-----------------------------------------------------------------"
	@echo "Wordpress"
	@docker exec -it wordpress /bin/sh -c "cat /var/log/php83/error.log"
	@echo "-----------------------------------------------------------------"
	@docker-compose -f srcs/docker-compose.yml logs -f

check_web:
	curl -vI https://suham.42.fr

# Open a shell in the container
in_mariadb:
	@docker exec -it mariadb /bin/sh
in_wordpress:
	@docker exec -it wordpress /bin/sh
in_nginx:
	@docker exec -it nginx /bin/sh

# Build the docker containers
build: clean
	@mkdir -p /home/suham/data/mariadb
	@mkdir -p /home/suham/data/wordpress
	@chmod -R 777 ./srcs
	@docker-compose -f srcs/docker-compose.yml build --no-cache

# Clean up all containers, networks, and volumes
clean: down
	@docker-compose -f srcs/docker-compose.yml down -v --rmi all --remove-orphans
	@rm -rf /home/suham/data

.PHONY: build up down clean logs
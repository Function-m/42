COMPOSE_FILE		    := docker-compose.yml

all:
	DOCKER_BUILDKIT=1 docker-compose -f $(COMPOSE_FILE) up --build -d

clean:
	docker-compose -f $(COMPOSE_FILE) down

fclean:
	docker-compose -f $(COMPOSE_FILE) down --rmi all --volumes --remove-orphans
	docker system prune --all --volumes --force

re:
	make fclean
	make all

.PHONY: all clean fclean re
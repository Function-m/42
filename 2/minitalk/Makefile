CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = $(SERVER_NAME) $(CLIENT_NAME)

SERVER_NAME = server
CLIENT_NAME = client
OBJ_DIR = obj/

ifdef BONUS_FLAG

SRC_DIR = src_bonus/
UTILS_DIR = src_bonus/utils_bonus/
HEADER_DIR = include_bonus

UTILS = handle_exit_bonus.c handle_kill_bonus.c handle_write_bonus.c num_to_str_bonus.c str_to_num_bonus.c
SERVER_SRC = server_bonus.c $(UTILS)
CLIENT_SRC = client_bonus.c $(UTILS)

SERVER_OBJ = $(addprefix $(OBJ_DIR), $(SERVER_SRC:.c=.o))
CLIENT_OBJ = $(addprefix $(OBJ_DIR), $(CLIENT_SRC:.c=.o))

else

SRC_DIR = src/
UTILS_DIR = src/utils/
HEADER_DIR = include

UTILS = handle_exit.c handle_kill.c handle_write.c num_to_str.c str_to_num.c
SERVER_SRC = server.c $(UTILS)
CLIENT_SRC = client.c $(UTILS)

SERVER_OBJ = $(addprefix $(OBJ_DIR), $(SERVER_SRC:.c=.o))
CLIENT_OBJ = $(addprefix $(OBJ_DIR), $(CLIENT_SRC:.c=.o))

endif

all: $(NAME)

bonus:
	$(MAKE) BONUS_FLAG=1 all

$(SERVER_NAME): $(SERVER_OBJ)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -o $@ $^

$(CLIENT_NAME): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -o $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re

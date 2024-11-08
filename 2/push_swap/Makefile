CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

OBJ_DIR = obj
SRC_DIR = src
SUB_DIRS = data operations sort utils operations_extended stack

SRC_MAIN = main.c
SRC_SUB = \
	stack/find_extreme_index.c stack/init_stack.c stack/index_by_ascending_content.c stack/push_to_bottom.c \
	operations/print.c operations/rotate.c operations/push.c operations/reverse_rotate.c operations/swap.c \
	operations_extended/push_all_to_be_sorted_on_a.c operations_extended/push_all_to_be_sorted_on_a_sub.c operations_extended/push_all_expect_three_to_b.c \
	sort/sort_large.c sort/sort_stacks.c sort/is_sorted.c sort/sort_small.c \
	utils/handle_exit.c utils/get_strlen.c utils/is_numeric.c utils/get_numlen.c utils/convert_to_split_str.c utils/convert_str_to_int.c utils/handle_write.c utils/handle_malloc.c

OBJ_MAIN = $(SRC_MAIN:%.c=$(OBJ_DIR)/%.o)
OBJ_SUB = $(SRC_SUB:%.c=$(OBJ_DIR)/%.o)
OBJ = $(OBJ_MAIN) $(OBJ_SUB)

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(foreach DIR, $(SUB_DIRS), $(OBJ_DIR)/$(DIR))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
	rm -rf $(OBJ_DIR_BONUS)

# bonus
BONUS_NAME = checker

OBJ_DIR_BONUS = obj_bonus
SRC_DIR_BONUS = src_bonus
SUB_DIRS_BONUS = data_bonus operations_bonus sort_bonus utils_bonus stack_bonus get_next_line_bonus sort_bonus

SRC_MAIN_BONUS = main_bonus.c it_bonus_time.c
SRC_SUB_BONUS = \
	sort_bonus/is_sorted_bonus.c \
	stack_bonus/find_extreme_index_bonus.c stack_bonus/init_stack_bonus.c stack_bonus/index_by_ascending_content_bonus.c stack_bonus/push_to_bottom_bonus.c \
	operations_bonus/swap_bonus.c operations_bonus/reverse_rotate_bonus.c operations_bonus/rotate_bonus.c operations_bonus/push_bonus.c \
	utils_bonus/is_numeric_bonus.c utils_bonus/convert_to_split_str_bonus.c utils_bonus/handle_exit_bonus.c utils_bonus/get_strlen_bonus.c utils_bonus/handle_malloc_bonus.c utils_bonus/is_same_str.c utils_bonus/get_numlen_bonus.c utils_bonus/handle_write_bonus.c utils_bonus/convert_str_to_int_bonus.c

OBJ_MAIN_BONUS = $(SRC_MAIN_BONUS:%.c=$(OBJ_DIR_BONUS)/%.o)
OBJ_SUB_BONUS = $(SRC_SUB_BONUS:%.c=$(OBJ_DIR_BONUS)/%.o)
OBJ_BONUS = $(OBJ_MAIN_BONUS) $(OBJ_SUB_BONUS)

$(OBJ_DIR_BONUS):
	mkdir -p $(OBJ_DIR_BONUS) $(foreach DIR, $(SUB_DIRS_BONUS), $(OBJ_DIR_BONUS)/$(DIR))

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c | $(OBJ_DIR_BONUS)
	$(CC) $(CFLAGS) -Iinclude_bonus -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME) : $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) -o $(BONUS_NAME)
	rm -rf $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(OBJ_DIR_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus

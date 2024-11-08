CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

NAME = so_long
OBJDIR = object/
BONUS_FLAG ?= 0

ifeq ($(BONUS_FLAG),1)
SRCDIR = source_bonus/
SRCS = main_bonus.c \
       mlx_handler/collision_event_bonus.c \
       mlx_handler/draw_all_bonus.c \
       mlx_handler/handle_mlx_xpm_file_to_image_bonus.c \
       mlx_handler/initialize_img_bonus.c \
       mlx_handler/initialize_mlx_bonus.c \
       mlx_handler/initialize_win_bonus.c \
       mlx_handler/initialize_win_event_bonus.c \
       mlx_handler/key_event_bonus.c \
       parse_ber_into_data/parse_ber_into_data_bonus.c \
       parse_ber_into_data/validate/is_closedness_by_wall_bonus.c \
       parse_ber_into_data/validate/is_reachable_bonus.c \
       parse_ber_into_data/validate/is_rectangular_bonus.c \
       parse_ber_into_data/validate/is_valid_chr_bonus.c \
       util/do_read_all_bonus.c \
       util/do_split_str_bonus.c \
       util/get_file_size_bonus.c \
       util/get_str_from_int_bonus.c \
       util/get_str_len_bonus.c \
       util/is_same_str_bonus.c \
       util/wrapper/handle_close_bonus.c \
       util/wrapper/handle_exit_bonus.c \
       util/wrapper/handle_free_bonus.c \
       util/wrapper/handle_malloc_bonus.c \
       util/wrapper/handle_open_bonus.c \
       util/wrapper/handle_read_bonus.c \
       util/wrapper/handle_write_bonus.c
else
SRCDIR = source/
SRCS = main.c \
       mlx_handler/collision_event.c \
       mlx_handler/draw_all.c \
       mlx_handler/handle_mlx_xpm_file_to_image.c \
       mlx_handler/initialize_img.c \
       mlx_handler/initialize_mlx.c \
       mlx_handler/initialize_win.c \
       mlx_handler/initialize_win_event.c \
       mlx_handler/key_event.c \
       parse_ber_into_data/parse_ber_into_data.c \
       parse_ber_into_data/validate/is_closedness_by_wall.c \
       parse_ber_into_data/validate/is_reachable.c \
       parse_ber_into_data/validate/is_rectangular.c \
       parse_ber_into_data/validate/is_valid_chr.c \
       util/do_read_all.c \
       util/do_split_str.c \
       util/get_file_size.c \
       util/get_str_from_int.c \
       util/get_str_len.c \
       util/is_same_str.c \
       util/wrapper/handle_close.c \
       util/wrapper/handle_exit.c \
       util/wrapper/handle_free.c \
       util/wrapper/handle_malloc.c \
       util/wrapper/handle_open.c \
       util/wrapper/handle_read.c \
       util/wrapper/handle_write.c
endif

OBJS = $(SRCS:%.c=$(OBJDIR)%.o)

INCLUDES = -I include
LIBS = -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

bonus:
	$(MAKE) BONUS_FLAG=1 all

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus


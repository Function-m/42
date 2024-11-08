BONUS_FLAG ?= 0
NAME = cub3D
MANDATORY_OBJ_DIR = ./object/mandatory
BONUS_OBJ_DIR = ./object/bonus

MANDATORY_SRC_DIR = ./mandatory
MANDATORY_SRC_NAME = main.c \
	0_validate_main_arg/validate_main_arg.c \
	1_parse_cub_into_cub3d_struct/init_player.c \
	1_parse_cub_into_cub3d_struct/parse_cub_into_cub3d_struct.c \
	1_parse_cub_into_cub3d_struct/parse_element.c \
	1_parse_cub_into_cub3d_struct/parse_map.c \
	1_parse_cub_into_cub3d_struct/utils/skip_empty_line.c \
	1_parse_cub_into_cub3d_struct/utils/skip_spaces.c \
	1_parse_cub_into_cub3d_struct/validate_map.c \
	2_init_cub3d/init_cub3d.c \
	2_init_cub3d/init_door.c \
	2_init_cub3d/init_mlx.c \
	2_init_cub3d/init_texture.c \
	3_init_window_event/init_window_event.c \
	4_run_mlx_loop/clear_screen.c \
	4_run_mlx_loop/door_keeper.c \
	4_run_mlx_loop/draw.c \
	4_run_mlx_loop/draw_minimap.c \
	4_run_mlx_loop/move_player.c \
	4_run_mlx_loop/raycasting/raycasting_0.c \
	4_run_mlx_loop/raycasting/raycasting_1.c \
	4_run_mlx_loop/run_mlx_loop.c \
	utils/ft_atoi.c \
	utils/ft_isspace.c \
	utils/ft_memset.c \
	utils/ft_read.c \
	utils/ft_strchr.c \
	utils/ft_strlen.c \
	utils/ft_strncmp.c \
	utils/ft_strncpy.c \
	utils/ft_strrcmp.c \
	utils/wrapper/exit_routine.c \
	utils/wrapper/file_manager.c \
	utils/wrapper/io_controller.c \
	utils/wrapper/mem_handler.c \
	utils/wrapper/mlx_error_guard.c

BONUS_SRC_DIR = ./bonus
BONUS_SRC_NAME = main_bonus.c \
	0_validate_main_arg/validate_main_arg_bonus.c \
	1_parse_cub_into_cub3d_struct/init_player_bonus.c \
	1_parse_cub_into_cub3d_struct/parse_cub_into_cub3d_struct_bonus.c \
	1_parse_cub_into_cub3d_struct/parse_element_bonus.c \
	1_parse_cub_into_cub3d_struct/parse_map_bonus.c \
	1_parse_cub_into_cub3d_struct/utils/skip_empty_line_bonus.c \
	1_parse_cub_into_cub3d_struct/utils/skip_spaces_bonus.c \
	1_parse_cub_into_cub3d_struct/validate_map_bonus.c \
	2_init_cub3d/init_cub3d_bonus.c \
	2_init_cub3d/init_door_bonus.c \
	2_init_cub3d/init_mlx_bonus.c \
	2_init_cub3d/init_texture_bonus.c \
	3_init_window_event/init_window_event_bonus.c \
	4_run_mlx_loop/clear_screen_bonus.c \
	4_run_mlx_loop/door_keeper_bonus.c \
	4_run_mlx_loop/draw_bonus.c \
	4_run_mlx_loop/draw_minimap_bonus.c \
	4_run_mlx_loop/move_player_bonus.c \
	4_run_mlx_loop/raycasting/raycasting_0_bonus.c \
	4_run_mlx_loop/raycasting/raycasting_1_bonus.c \
	4_run_mlx_loop/run_mlx_loop_bonus.c \
	utils/ft_atoi_bonus.c \
	utils/ft_isspace_bonus.c \
	utils/ft_memset_bonus.c \
	utils/ft_read_bonus.c \
	utils/ft_strchr_bonus.c \
	utils/ft_strlen_bonus.c \
	utils/ft_strncmp_bonus.c \
	utils/ft_strncpy_bonus.c \
	utils/ft_strrcmp_bonus.c \
	utils/wrapper/exit_routine_bonus.c \
	utils/wrapper/file_manager_bonus.c \
	utils/wrapper/io_controller_bonus.c \
	utils/wrapper/mem_handler_bonus.c \
	utils/wrapper/mlx_error_guard_bonus.c

ifeq ($(BONUS_FLAG),1)
	SRC_DIR = $(BONUS_SRC_DIR)
	SRC_NAME = $(BONUS_SRC_NAME)
	OBJ_DIR = $(BONUS_OBJ_DIR)
else
	SRC_DIR = $(MANDATORY_SRC_DIR)
	SRC_NAME = $(MANDATORY_SRC_NAME)
	OBJ_DIR = $(MANDATORY_OBJ_DIR)
endif

SRCS = $(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

MLX_NAME = mlx
MLX_DIR = ./mlx/
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: clean_opposite
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -L $(MLX_DIR) -o $(NAME)
	install_name_tool -change libmlx.dylib $(MLX_DIR)/libmlx.dylib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	$(MAKE) BONUS_FLAG=1 all

clean_opposite:
ifeq ($(BONUS_FLAG),1)
	rm -rf $(MANDATORY_OBJ_DIR)
else
	rm -rf $(BONUS_OBJ_DIR)
endif

clean:
	rm -rf object

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re bonus
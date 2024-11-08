/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngjin <youngjin@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 05:37:47 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 02:25:40 by youngjin         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdbool.h>
# include <math.h>
# include "utils/utils.h"

// Window Event
# define KEY_PRESS		2
# define KEY_RELEASE	3
# define MOUSE_MOVE		6
# define WIN_CLOSE 		17

// Window Size
# define WIN_WIDTH	800
# define WIN_HEIGHT	600

// Player Movement Speed
# define MOVE_SPEED	0.2
# define ROT_SPEED	0.02

// MiniMap Size
# define MINIMAP_SCALE		2
# define MINIMAP_CELL_SIZE	4
# define MINIMAP_HEIGHT	15
# define MINIMAP_WIDTH	15

// Keycode
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_ESC 53
# define KEYCODE_MAX 64

// Exit Message
# define MSG_SUCCESS_EXIT\
	"The program was successfully terminated.\n"
# define ERRMSG_COLOR\
	"Error\nRGB colors are wrong in the .cub file.\n"
# define ERRMSG_MULTIPLE_PLAYERS\
	"Error\nThere are two or more players in the .cub file.\n"
# define ERRMSG_NO_PLAYER\
	"Error\nThere's no player in the .cub file.\n"
# define ERRMSG_CUB_FILE\
	"Error\nThere is something wrong with .cub file.\n"
# define ERRMSG_IDENTIFIERS\
	"Error\nIdentifiers is duplicated in the .cub file.\n"
# define ERRMSG_ARGUMENT\
	"Error\nThere is incorrect arguments.\n"

typedef struct s_img
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_position
{
	double	x;
	double	y;
}	t_position;

typedef struct s_cub3d
{
	struct s_env
	{
		void	*mlx;
		void	*win;
		t_img	screen;
	}	env;
	struct s_map
	{
		char	*origin_file;
		char	**data;
		size_t	width;
		size_t	height;
	}	map;
	struct s_user_input
	{
		bool	key[KEYCODE_MAX];
	}	user_input;
	struct s_file_path
	{
		char	*east;
		char	*west;
		char	*south;
		char	*north;
		char	*door[3];
	}	file_path;
	struct s_texture
	{
		t_img	east;
		t_img	west;
		t_img	south;
		t_img	north;
		t_img	door[3];
	}	texture;
	struct s_player
	{
		t_position	pos;
		t_position	dir;
		t_position	plane;
	}	player;
	struct s_color
	{
		int	ceiling;
		int	floor;
	}	color;
}	t_cub3d;

// Step 0
void	validate_main_arg(int argc, char *argv);

// Step 1
void	parse_cub_file_into_cub3d_struct(t_cub3d *cub3d, char *cub_file_path);

// Step 2
void	init_cub3d(t_cub3d *cub3d);

// Step 3
void	init_window_event(t_cub3d *cub3d);

// Step 4
void	run_mlx_loop(t_cub3d *cub3d);

#endif
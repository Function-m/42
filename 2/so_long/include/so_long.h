/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:14:30 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 05:31:03 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>

// Program window title
# define TITLE	"So Long"

// For key event
# define KEY_COUNT		280
# define KEYCODE_ESC	53
# define KEYCODE_W		13
# define KEYCODE_A		0
# define KEYCODE_S		1
# define KEYCODE_D		2

// For map tile
# define MAP_GRID			80
# define MAP_EMPTY			'0'
# define MAP_WALL			'1'
# define MAP_COLLETIABLE	'C'
# define MAP_EXIT			'E'
# define MAP_PLAYER			'P'

// Print before error msg
# define PRE_ERR_MSG	"Error\n"

// Standard FD
# define STDOUT_FD	1
# define STDERR_FD	2

// NULL pointer
# define NULL_PTR	((void *)0)

// Typical return value of function
# define SUCCESS	0
# define FAILURE	-1

// Boolean value
# define TRUE	1
# define FALSE	0

// 'open' function's flag
# define RDONLY 0x0000

// Shortened type
typedef long long			t_ll;
typedef unsigned long long	t_ull;

// MLX img's information
typedef struct s_img
{
	void	*ptr;
	char	*file_path;
}	t_img;

// Context data type
typedef struct s_data
{
	struct s_minilibx
	{
		void	*ptr;
		int		tick;
	}	mlx;
	struct s_window
	{
		void	*ptr;
		char	*title;
	}	win;
	struct s_imgs
	{
		void	*background;
		void	*wall;
		void	*exit;
		void	*collectible;
		void	*player[4];
		void	*enemy[2];
	}	img;
	struct s_input
	{
		int	key[KEY_COUNT];
	}	input;
	struct s_map
	{
		char	**tile;
		int		width;
		int		height;
	}	map;
	struct s_entity
	{
		int	player[2];
		int	enemy[2];
	}	entity;
}	t_data;

// Util
int		is_same_str(const char *one, const char *two);
t_ull	get_str_len(const char *str);
t_ull	get_file_size(const char *file_path);
void	get_str_from_int(int num, char *str, int str_size);
char	*do_read_all(const char *file_path);
char	**do_split_str(char *str, char delimiter);
t_ll	handle_write(int fd, const char *str);
t_ll	handle_read(int fd, void *buf, t_ull bytes);
int		handle_open(const char *path);
void	handle_close(int fd);
void	handle_exit(int status, char *msg);
void	handle_free(void *ptr);
void	*handle_malloc(t_ll size);

// Parse ber into data
void	parse_ber_into_data(t_data *data, char *ber_path);
int		is_closedness_by_wall(t_data *data);
int		is_rectangular(t_data *data);
int		is_valid_chr(int tile);
int		is_reachable(t_data *data, int x, int y);

// MLX handler
void	*handle_mlx_xpm_file_to_image(t_data *data, char *xpm_path);
void	draw_all(t_data *data);
void	initialize_mlx(t_data *data);
void	initialize_win(t_data *data);
void	initialize_img(t_data *data);
void	initialize_win_event(t_data *data);
void	key_event(t_data *data);
void	collision_event(t_data *data);

#endif

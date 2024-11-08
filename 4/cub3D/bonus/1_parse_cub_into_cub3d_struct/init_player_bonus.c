/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:22:27 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 02:49:22 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	exit_with_error(char *message, int code)
{
	write(2, message, ft_strlen(message));
	do_exit(code);
}

static bool	find_player(t_cub3d *cub3d, char **map, size_t x, size_t y)
{
	if (map[y][x] == 'N' || map[y][x] == 'S'
		|| map[y][x] == 'E' || map[y][x] == 'W')
	{
		cub3d->player.pos.x = (double)x + 0.5;
		cub3d->player.pos.y = (double)y + 0.5;
		cub3d->player.dir.x = (map[y][x] == 'E') - (map[y][x] == 'W');
		cub3d->player.dir.y = (map[y][x] == 'S') - (map[y][x] == 'N');
		map[y][x] = '0';
		return (true);
	}
	return (false);
}

static void	init_plane(t_cub3d *cub3d)
{
	if (cub3d->player.dir.x == 1)
	{
		cub3d->player.plane.y = -0.66;
		cub3d->player.plane.x = 0;
	}
	else if (cub3d->player.dir.x == -1)
	{
		cub3d->player.plane.y = 0.66;
		cub3d->player.plane.x = 0;
	}
	else if (cub3d->player.dir.y == 1)
	{
		cub3d->player.plane.y = 0;
		cub3d->player.plane.x = 0.66;
	}
	else if (cub3d->player.dir.y == -1)
	{
		cub3d->player.plane.y = 0;
		cub3d->player.plane.x = -0.66;
	}
}

void	init_player(t_cub3d *cub3d)
{
	size_t	y;
	size_t	x;
	bool	is_exist;

	is_exist = false;
	y = 0;
	while (cub3d->map.data[y])
	{
		x = 0;
		while (cub3d->map.data[y][x])
		{
			if (find_player(cub3d, cub3d->map.data, x, y))
			{
				if (is_exist)
					exit_with_error(ERRMSG_MULTIPLE_PLAYERS, 1);
				is_exist = true;
			}
			x++;
		}
		y++;
	}
	if (!is_exist)
		exit_with_error(ERRMSG_NO_PLAYER, 1);
	init_plane(cub3d);
}

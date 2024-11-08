/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 18:08:51 by suham             #+#    #+#             */
/*   Updated: 2024/02/17 11:17:28 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_wall(t_cub3d *cub3d, int x, int y)
{
	if (x < 0 || x >= (int)cub3d->map.width || \
	y < 0 || y >= (int)cub3d->map.height)
		return (true);
	return (cub3d->map.data[y][x] == '1');
}

void	try_move(t_cub3d *cub3d, double move_x, double move_y)
{
	if (!is_wall(cub3d, (int)(cub3d->player.pos.x + move_x), \
	(int)cub3d->player.pos.y))
		cub3d->player.pos.x += move_x;
	if (!is_wall(cub3d, (int)cub3d->player.pos.x, \
	(int)(cub3d->player.pos.y + move_y)))
		cub3d->player.pos.y += move_y;
}

void	rotate_player(t_cub3d *cub3d, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub3d->player.dir.x;
	cub3d->player.dir.x = cub3d->player.dir.x * cos(rot_speed) \
						- cub3d->player.dir.y * sin(rot_speed);
	cub3d->player.dir.y = old_dir_x * sin(rot_speed) \
						+ cub3d->player.dir.y * cos(rot_speed);
	old_plane_x = cub3d->player.plane.x;
	cub3d->player.plane.x = cub3d->player.plane.x * cos(rot_speed) \
							- cub3d->player.plane.y * sin(rot_speed);
	cub3d->player.plane.y = old_plane_x * sin(rot_speed) \
							+ cub3d->player.plane.y * cos(rot_speed);
}

void	key_event(t_cub3d *cub3d)
{
	if (cub3d->user_input.key[KEY_W])
		try_move(cub3d, cub3d->player.dir.x * MOVE_SPEED, \
		cub3d->player.dir.y * MOVE_SPEED);
	if (cub3d->user_input.key[KEY_S])
		try_move(cub3d, -cub3d->player.dir.x * MOVE_SPEED, \
		-cub3d->player.dir.y * MOVE_SPEED);
	if (cub3d->user_input.key[KEY_A])
		rotate_player(cub3d, ROT_SPEED);
	if (cub3d->user_input.key[KEY_D])
		rotate_player(cub3d, -ROT_SPEED);
	if (cub3d->user_input.key[KEY_ESC])
	{
		printf(MSG_SUCCESS_EXIT);
		exit(EXIT_SUCCESS);
	}
}

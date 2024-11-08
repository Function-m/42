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

#include "../cub3d_bonus.h"

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

void	key_event(t_cub3d *cub3d)
{
	if (cub3d->user_input.key[KEY_W])
		try_move(cub3d, cub3d->player.dir.x * MOVE_SPEED, \
		cub3d->player.dir.y * MOVE_SPEED);
	if (cub3d->user_input.key[KEY_S])
		try_move(cub3d, -cub3d->player.dir.x * MOVE_SPEED, \
		-cub3d->player.dir.y * MOVE_SPEED);
	if (cub3d->user_input.key[KEY_A])
		try_move(cub3d, -cub3d->player.plane.x * MOVE_SPEED, \
		-cub3d->player.plane.y * MOVE_SPEED);
	if (cub3d->user_input.key[KEY_D])
		try_move(cub3d, cub3d->player.plane.x * MOVE_SPEED, \
		cub3d->player.plane.y * MOVE_SPEED);
	if (cub3d->user_input.key[KEY_ESC])
	{
		printf(MSG_SUCCESS_EXIT);
		exit(EXIT_SUCCESS);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_keeper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:18:49 by suham             #+#    #+#             */
/*   Updated: 2024/02/17 16:39:27 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	open_door(t_cub3d *cub3d)
{
	size_t	x;
	size_t	y;
	double	distance;

	y = 0;
	while (y < cub3d->map.height)
	{
		x = 0;
		while (x < cub3d->map.width)
		{
			if (cub3d->map.data[y][x] == '2')
			{
				distance \
					= sqrt(pow(cub3d->player.pos.x - (x + 0.5), 2) \
						+ pow(cub3d->player.pos.y - (y + 0.5), 2));
				if (distance < 2)
					cub3d->map.data[y][x] = '3';
			}
			x++;
		}
		y++;
	}
}

void	close_door(t_cub3d *cub3d)
{
	size_t	x;
	size_t	y;
	double	distance;

	y = 0;
	while (y < cub3d->map.height)
	{
		x = 0;
		while (x < cub3d->map.width)
		{
			if (cub3d->map.data[y][x] == '3')
			{
				distance \
					= sqrt(pow(cub3d->player.pos.x - (x + 0.5), 2) \
						+ pow(cub3d->player.pos.y - (y + 0.5), 2));
				if (distance >= 2)
					cub3d->map.data[y][x] = '2';
			}
			x++;
		}
		y++;
	}
}

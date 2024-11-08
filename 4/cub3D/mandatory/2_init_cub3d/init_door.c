/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:11:57 by suham             #+#    #+#             */
/*   Updated: 2024/02/16 13:58:37 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_door(t_cub3d *cub3d)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < cub3d->map.height - 1)
	{
		x = 0;
		while (x < cub3d->map.width - 1)
		{
			if (cub3d->map.data[y][x] == '0')
			{
				if (cub3d->map.data[y - 1][x] == '1' \
						&& cub3d->map.data[y + 1][x] == '1')
					cub3d->map.data[y][x] = '2';
				else if (cub3d->map.data[y][x - 1] == '1' \
						&& cub3d->map.data[y][x + 1] == '1')
					cub3d->map.data[y][x] = '2';
			}
			x++;
		}
		y++;
	}
}

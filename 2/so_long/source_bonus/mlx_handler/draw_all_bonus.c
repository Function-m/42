/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_all_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 06:51:22 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:21:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw(t_data *data, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(\
			data->mlx.ptr, data->win.ptr, img_ptr, x * MAP_GRID, y * MAP_GRID);
}

static void	draw_with_shaking(t_data *data, void *img_ptr, int x, int y)
{
	if (data->mlx.tick < 50)
		mlx_put_image_to_window(
			data->mlx.ptr, data->win.ptr,
			img_ptr, x * MAP_GRID, y * MAP_GRID - data->mlx.tick / 10);
	else
		mlx_put_image_to_window(
			data->mlx.ptr, data->win.ptr,
			img_ptr, x * MAP_GRID, y * MAP_GRID - (100 - data->mlx.tick) / 10);
}

static void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (data->map.tile[y][x])
		{
			draw(data, data->img.background, x, y);
			if (data->map.tile[y][x] == MAP_WALL)
				draw(data, data->img.wall, x, y);
			if (data->map.tile[y][x] == MAP_COLLETIABLE)
				draw_with_shaking(data, data->img.collectible, x, y);
			if (data->map.tile[y][x] == MAP_EXIT)
				draw_with_shaking(data, data->img.exit, x, y);
			++x;
		}
		++y;
	}
}

static void	draw_entity(t_data *data)
{
	if (data->mlx.tick % 10 < 5)
	{
		draw(data, data->img.player[2],
			data->entity.player[0], data->entity.player[1]);
		draw(data, data->img.enemy[0],
			data->entity.enemy[0], data->entity.enemy[1]);
	}
	else
	{
		draw(data, data->img.player[3],
			data->entity.player[0], data->entity.player[1]);
		draw(data, data->img.enemy[1],
			data->entity.enemy[0], data->entity.enemy[1]);
	}
}

void	draw_all(t_data *data)
{
	draw_map(data);
	draw_entity(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 22:26:15 by youngjin          #+#    #+#             */
/*   Updated: 2024/02/18 02:49:22 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw(t_cub3d *cub3d, size_t x, size_t y, int rgb_color);

static void	draw_tile(t_cub3d *cub3d, size_t x, size_t y, int color)
{
	size_t	dx;
	size_t	dy;

	dy = 0;
	while (dy < MINIMAP_CELL_SIZE)
	{
		dx = 0;
		while (dx < MINIMAP_CELL_SIZE)
		{
			draw(cub3d, \
			x * MINIMAP_CELL_SIZE * MINIMAP_SCALE + dx * MINIMAP_SCALE, \
			y * MINIMAP_CELL_SIZE * MINIMAP_SCALE + dy * MINIMAP_SCALE, color);
			dx++;
		}
		dy++;
	}
}

static void	draw_map_tiles(t_cub3d *cub3d)
{
	size_t	x;
	size_t	y;
	size_t	map_x;
	size_t	map_y;

	y = 0;
	while (y < MINIMAP_HEIGHT)
	{
		x = 0;
		while (x < MINIMAP_WIDTH)
		{
			map_x = (cub3d->player.pos.x - MINIMAP_WIDTH / 2) + x;
			map_y = (cub3d->player.pos.y - MINIMAP_HEIGHT / 2) + y;
			if (map_x >= 0 && map_x < cub3d->map.width && \
				map_y >= 0 && map_y < cub3d->map.height)
			{
				if (cub3d->map.data[map_y][map_x] == '1')
					draw_tile(cub3d, x, y, 0xFFFFFF);
				else if (cub3d->map.data[map_y][map_x] == '2')
					draw_tile(cub3d, x, y, 0x00FF00);
			}
			x++;
		}
		y++;
	}
}

static void	draw_player_position(t_cub3d *cub3d)
{
	int	dx;
	int	dy;
	int	player_x;
	int	player_y;

	player_x = MINIMAP_WIDTH / 2 * MINIMAP_CELL_SIZE * MINIMAP_SCALE;
	player_y = MINIMAP_HEIGHT / 2 * MINIMAP_CELL_SIZE * MINIMAP_SCALE;
	dy = -2;
	while (dy <= 2)
	{
		dx = -2;
		while (dx <= 2)
		{
			draw(cub3d, player_x + dx, player_y + dy, 0xFF0000);
			dx++;
		}
		dy++;
	}
}

static void	draw_player_direction(t_cub3d *cub3d)
{
	int	dir_x;
	int	dir_y;
	int	player_x;
	int	player_y;
	int	line_length;

	line_length = 5;
	player_x = MINIMAP_WIDTH / 2 * MINIMAP_CELL_SIZE * MINIMAP_SCALE;
	player_y = MINIMAP_HEIGHT / 2 * MINIMAP_CELL_SIZE * MINIMAP_SCALE;
	dir_x = player_x + (int)(cub3d->player.dir.x * line_length * MINIMAP_SCALE);
	dir_y = player_y + (int)(cub3d->player.dir.y * line_length * MINIMAP_SCALE);
	draw(cub3d, dir_x, dir_y, 0x00FF00);
}

void	draw_minimap(t_cub3d *cub3d)
{
	draw_map_tiles(cub3d);
	draw_player_position(cub3d);
	draw_player_direction(cub3d);
}

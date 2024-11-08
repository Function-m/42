/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 07:18:07 by suham             #+#    #+#             */
/*   Updated: 2024/02/16 15:02:43 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw(t_cub3d *cub3d, size_t x, size_t y, int rgb_color);

void	clear_screen(t_cub3d *cub3d)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			draw(cub3d, x, y, cub3d->color.ceiling);
			x++;
		}
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			draw(cub3d, x, y, cub3d->color.floor);
			x++;
		}
		y++;
	}
}

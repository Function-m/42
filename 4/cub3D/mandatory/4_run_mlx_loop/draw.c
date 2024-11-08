/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:59:50 by suham             #+#    #+#             */
/*   Updated: 2024/02/17 21:55:44 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw(t_cub3d *cub3d, size_t x, size_t y, int rgb_color)
{
	int	offset;

	if (x < 0 && x >= WIN_WIDTH && y < 0 && y >= WIN_HEIGHT)
		return ;
	if ((unsigned int)rgb_color == 0xFF000000)
		rgb_color = 0xFFFFFF;
	offset = y * cub3d->env.screen.line_length \
				+ x * (cub3d->env.screen.bits_per_pixel / 8);
	*(int *)(cub3d->env.screen.data + offset) = rgb_color;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:11:57 by suham             #+#    #+#             */
/*   Updated: 2024/02/17 20:07:33 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_mlx(t_cub3d *cub3d)
{
	cub3d->env.mlx = do_mlx_init();
	cub3d->env.win \
		= do_mlx_new_window(cub3d->env.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	cub3d->env.screen.width = WIN_WIDTH;
	cub3d->env.screen.height = WIN_HEIGHT;
	cub3d->env.screen.img \
		= do_mlx_new_image(cub3d->env.mlx, WIN_WIDTH, WIN_HEIGHT);
	cub3d->env.screen.data \
		= mlx_get_data_addr \
			(cub3d->env.screen.img, &cub3d->env.screen.bits_per_pixel, \
				&cub3d->env.screen.line_length, &cub3d->env.screen.endian);
}

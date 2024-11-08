/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:11:57 by suham             #+#    #+#             */
/*   Updated: 2024/02/17 16:54:21 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	get_new_texture(t_cub3d *cub3d, t_img *new_texture, char *path)
{
	new_texture->img = do_mlx_xpm_file_to_image \
		(cub3d->env.mlx, path, &new_texture->width, &new_texture->height);
	new_texture->data = mlx_get_data_addr \
		(new_texture->img, &new_texture->bits_per_pixel, \
			&new_texture->line_length, &new_texture->endian);
}

void	init_texture(t_cub3d *cub3d)
{
	get_new_texture(cub3d, &cub3d->texture.east, cub3d->file_path.east);
	get_new_texture(cub3d, &cub3d->texture.west, cub3d->file_path.west);
	get_new_texture(cub3d, &cub3d->texture.south, cub3d->file_path.south);
	get_new_texture(cub3d, &cub3d->texture.north, cub3d->file_path.north);
	get_new_texture \
		(cub3d, &cub3d->texture.door[0], "asset/textures/door_0.xpm");
	get_new_texture \
		(cub3d, &cub3d->texture.door[1], "asset/textures/door_1.xpm");
	get_new_texture \
		(cub3d, &cub3d->texture.door[2], "asset/textures/door_2.xpm");
}

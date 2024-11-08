/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_img_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:53:19 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:21:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initialize_img(t_data *data)
{
	data->img.background = handle_mlx_xpm_file_to_image(data, \
		"asset/xpm/background.xpm");
	data->img.exit = handle_mlx_xpm_file_to_image(data, \
		"asset/xpm/exit.xpm");
	data->img.wall = handle_mlx_xpm_file_to_image(data, \
		"asset/xpm/wall.xpm");
	data->img.collectible = handle_mlx_xpm_file_to_image(data, \
		"asset/xpm/collectible.xpm");
	data->img.player[0] = handle_mlx_xpm_file_to_image(data, \
		"asset/xpm/player_0.xpm");
	data->img.player[1] = handle_mlx_xpm_file_to_image(data, \
		"asset/xpm/player_1.xpm");
	data->img.player[2] = handle_mlx_xpm_file_to_image(data, \
		"asset/xpm/player_2.xpm");
	data->img.player[3] = handle_mlx_xpm_file_to_image(data, \
		"asset/xpm/player_3.xpm");
	data->img.enemy[0] = handle_mlx_xpm_file_to_image(data, \
		"asset/xpm/enemy_0.xpm");
	data->img.enemy[1] = handle_mlx_xpm_file_to_image(data, \
		"asset/xpm/enemy_1.xpm");
}

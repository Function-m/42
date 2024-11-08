/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub3d_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:42:32 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 02:49:22 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	init_mlx(t_cub3d *cub3d);
void	init_door(t_cub3d *cub3d);
void	init_texture(t_cub3d *cub3d);

void	init_cub3d(t_cub3d *cub3d)
{
	init_mlx(cub3d);
	init_door(cub3d);
	init_texture(cub3d);
}

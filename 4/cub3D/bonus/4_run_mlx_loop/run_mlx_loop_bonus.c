/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_mlx_loop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 07:18:07 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 02:49:22 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	raycasting(t_cub3d *cub3d);
void	clear_screen(t_cub3d *cub3d);
void	draw_minimap(t_cub3d *cub3d);
void	key_event(t_cub3d *cub3d);
void	open_door(t_cub3d *cub3d);
void	close_door(t_cub3d *cub3d);

int	main_routine(t_cub3d *cub3d)
{
	static int	throttling = 0;

	if (throttling == 150)
		throttling = 0;
	if (throttling++ != 0)
		return (0);
	clear_screen(cub3d);
	key_event(cub3d);
	open_door(cub3d);
	close_door(cub3d);
	raycasting(cub3d);
	draw_minimap(cub3d);
	mlx_put_image_to_window(cub3d->env.mlx, \
		cub3d->env.win, cub3d->env.screen.img, 0, 0);
	return (0);
}

void	run_mlx_loop(t_cub3d *cub3d)
{
	mlx_loop_hook(cub3d->env.mlx, main_routine, cub3d);
	mlx_loop(cub3d->env.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 06:33:22 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 03:10:19 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

struct s_mouse_move_var
{
	double	rot_angle;
	double	cos_rot;
	double	sin_rot;
	double	old_dir_x;
	double	old_plane_x;
};

int	key_press(int keycode, t_cub3d *cub3d)
{
	if (keycode < KEYCODE_MAX)
		cub3d->user_input.key[keycode] = true;
	return (0);
}

int	key_release(int keycode, t_cub3d *cub3d)
{
	if (keycode < KEYCODE_MAX)
		cub3d->user_input.key[keycode] = false;
	return (0);
}

int	win_close(t_cub3d *cub3d)
{
	(void)cub3d;
	printf(MSG_SUCCESS_EXIT);
	exit(EXIT_SUCCESS);
	return (0);
}

void	init_window_event(t_cub3d *cub3d)
{
	ft_memset(cub3d->user_input.key, false, KEYCODE_MAX);
	mlx_hook(cub3d->env.win, KEY_RELEASE, 0, key_release, cub3d);
	mlx_hook(cub3d->env.win, KEY_PRESS, 0, key_press, cub3d);
	mlx_hook(cub3d->env.win, WIN_CLOSE, 0, win_close, cub3d);
}

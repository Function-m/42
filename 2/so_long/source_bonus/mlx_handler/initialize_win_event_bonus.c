/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_win_event_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:33:20 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:24:09 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#define WIN_CLOSE_EVENT 17

int	win_close(t_data *data)
{
	(void)data;
	handle_exit(SUCCESS, "The program was successfully completed.\n");
	return (SUCCESS);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode < KEY_COUNT)
		data->input.key[keycode] = TRUE;
	return (SUCCESS);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode < KEY_COUNT)
		data->input.key[keycode] = FALSE;
	return (SUCCESS);
}

void	initialize_win_event(t_data *data)
{
	data->input.key[KEYCODE_W] = FALSE;
	data->input.key[KEYCODE_A] = FALSE;
	data->input.key[KEYCODE_S] = FALSE;
	data->input.key[KEYCODE_D] = FALSE;
	data->input.key[KEYCODE_ESC] = FALSE;
	mlx_hook(data->win.ptr, 2, 0, key_press, data);
	mlx_hook(data->win.ptr, 3, 0, key_release, data);
	mlx_hook(data->win.ptr, 17, 0, win_close, data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_win.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:33:20 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 03:31:29 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_win(t_data *data)
{
	data->win.ptr = mlx_new_window(data->mlx.ptr, \
		data->map.width * MAP_GRID, data->map.height * MAP_GRID + 30, TITLE);
	if (!(data->win.ptr))
		handle_exit(FAILURE, "'mlx_new_window' function failed\n");
}

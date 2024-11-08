/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 08:33:20 by suham             #+#    #+#             */
/*   Updated: 2023/11/23 17:37:16 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_mlx(t_data *data)
{
	data->mlx.ptr = mlx_init();
	if (!(data->mlx.ptr))
		handle_exit(FAILURE, "'mlx_init' function failed\n");
	data->mlx.tick = 0;
}

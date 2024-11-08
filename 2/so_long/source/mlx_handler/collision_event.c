/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 20:49:50 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 03:35:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	has_collectible(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.tile[y][x] == MAP_COLLETIABLE)
				return (TRUE);
			++x;
		}
		++y;
	}
	return (FALSE);
}

void	collision_event(t_data *data)
{
	int	chr;

	chr = data->map.tile[data->entity.player[1]][data->entity.player[0]];
	if (data->entity.player[0] == data->entity.enemy[0]
		&& data->entity.player[1] == data->entity.enemy[1])
		handle_exit(SUCCESS,
			"The program was successfully completed.\n\
				And lost the game.\n");
	if (chr == MAP_COLLETIABLE)
		data->map.tile[data->entity.player[1]][data->entity.player[0]] = '0';
	if (chr == MAP_EXIT && !(has_collectible(data)))
		handle_exit(SUCCESS,
			"The program was successfully completed.\n\
				And the game was cleared.\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_closedness_by_wall_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:07:11 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:21:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_closedness_by_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.height)
	{
		if (data->map.tile[i][0] != MAP_WALL)
			return (FALSE);
		if (data->map.tile[i][data->map.width - 1] != MAP_WALL)
			return (FALSE);
		++i;
	}
	i = 0;
	while (i < data->map.width)
	{
		if (data->map.tile[0][i] != MAP_WALL)
			return (FALSE);
		if (data->map.tile[data->map.height - 1][i] != MAP_WALL)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

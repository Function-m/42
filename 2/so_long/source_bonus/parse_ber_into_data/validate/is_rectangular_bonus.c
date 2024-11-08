/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangular_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:07:30 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:21:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_rectangular(t_data *data)
{
	int	i;
	int	line_len;

	i = 0;
	while (i < data->map.height)
	{
		line_len = get_str_len(data->map.tile[i]);
		if (line_len != data->map.width)
			return (FALSE);
		++i;
	}
	return (TRUE);
}

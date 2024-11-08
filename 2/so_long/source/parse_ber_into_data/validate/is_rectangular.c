/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_rectangular.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:07:30 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 05:41:29 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

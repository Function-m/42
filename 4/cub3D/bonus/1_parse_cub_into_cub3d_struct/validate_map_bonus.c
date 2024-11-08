/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:44:44 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 02:49:22 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	is_valid_surroundings(char **map, int y, int x)
{
	if ((y == 0 || x == 0 || map[y + 1] == NULL)
		|| (map[y - 1][x] != '1' && map[y - 1][x] != '0')
		|| (map[y + 1][x] != '1' && map[y + 1][x] != '0')
		|| (map[y][x - 1] != '1' && map[y][x - 1] != '0')
		|| (map[y][x + 1] != '1' && map[y][x + 1] != '0'))
		return (false);
	return (true);
}

void	validate_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] != '0' && map[y][x] != '1' && map[y][x] != ' ')
				|| (map[y][x] == '0' && !is_valid_surroundings(map, y, x)))
			{
				write(2,
					"Error\nMap characters are wrong in the .cub file.\n", 49);
				do_exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}

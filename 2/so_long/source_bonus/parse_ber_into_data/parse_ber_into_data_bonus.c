/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ber_into_data_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:36:57 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:21:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	validate_tile_sub(t_data *data, int x, int y, int *existence_flag)
{
	if (!(is_valid_chr(data->map.tile[y][x])))
		handle_exit(FAILURE, "The map contains invalid characters.\n");
	if (data->map.tile[y][x] != MAP_WALL && !(is_reachable(data, x, y)))
		handle_exit(FAILURE,
			"There is no one player on the map, \
				or there are areas that cannot be reached.\n");
	if (data->map.tile[y][x] == MAP_EXIT)
		++(existence_flag[0]);
	if (data->map.tile[y][x] == MAP_PLAYER)
		++(existence_flag[1]);
	if (data->map.tile[y][x] == MAP_COLLETIABLE)
		++(existence_flag[2]);
}

static void	validate_tile(t_data *data)
{
	int	existence_flag[3];
	int	x;
	int	y;

	existence_flag[0] = 0;
	existence_flag[1] = 0;
	existence_flag[2] = 0;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (data->map.tile[y][x])
		{
			validate_tile_sub(data, x, y, existence_flag);
			++x;
		}
		++y;
	}
	if (existence_flag[0] != 1)
		handle_exit(FAILURE, "Exit is incorrect.\n");
	if (existence_flag[1] != 1)
		handle_exit(FAILURE, "Player is incorrect.\n");
	if (existence_flag[2] < 1)
		handle_exit(FAILURE, "Collectable is not in the map.\n");
}

static void	validate_map(t_data *data)
{
	if (!(is_rectangular(data)))
		handle_exit(FAILURE, "The map is not square.\n");
	if (!(is_closedness_by_wall(data)))
		handle_exit(FAILURE, "The map is not closed by a wall.\n");
}

static void	calculate_map_size(t_data *data)
{
	data->map.width = get_str_len(data->map.tile[0]);
	data->map.height = 0;
	while (data->map.tile[data->map.height])
		data->map.height++;
}

void	parse_ber_into_data(t_data *data, char *ber_path)
{
	data->map.tile = do_split_str(do_read_all(ber_path), '\n');
	calculate_map_size(data);
	validate_map(data);
	validate_tile(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:43:04 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:04:50 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_argument_of_main(int argc, char **argv)
{
	if (argc != 2)
		handle_exit(FAILURE, "The number of arguments is incorrect.\n");
	if (!(is_same_str(".ber", argv[1] + get_str_len(argv[1]) - 4)))
		handle_exit(FAILURE, "The extension of arguments is incorrect.\n");
}

void	update_entity_position(t_data *data)
{
	int	y;
	int	x;

	data->entity.enemy[0] -= 5;
	data->entity.enemy[1] -= 5;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (data->map.tile[y][x])
		{
			if (data->map.tile[y][x] == MAP_PLAYER)
			{
				data->entity.player[0] = x;
				data->entity.player[1] = y;
				return ;
			}
			++x;
		}
		++y;
	}
}

int	loop_callback(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	key_event(data);
	collision_event(data);
	draw_all(data);
	if (data->mlx.tick++ > 100)
		data->mlx.tick = 0;
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	validate_argument_of_main(argc, argv);
	parse_ber_into_data(&data, argv[1]);
	update_entity_position(&data);
	initialize_mlx(&data);
	initialize_win(&data);
	initialize_img(&data);
	initialize_win_event(&data);
	mlx_loop_hook(data.mlx.ptr, loop_callback, &data);
	mlx_loop(data.mlx.ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:48:39 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:38:39 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_chase_player(t_data *data)
{
	static int	count;
	int			diff_x;
	int			diff_y;

	if (count++ != 2)
		return ;
	diff_x = data->entity.player[0] - data->entity.enemy[0];
	diff_y = data->entity.player[1] - data->entity.enemy[1];
	if (diff_x > 0)
		data->entity.enemy[0]++;
	else if (diff_x < 0)
		data->entity.enemy[0]--;
	if (diff_y > 0)
		data->entity.enemy[1]++;
	else if (diff_y < 0)
		data->entity.enemy[1]--;
	count = 0;
}

static void	draw_black_bottom(t_data *data)
{
	int	i;
	int	j;

	i = data->map.height * MAP_GRID;
	while (i < data->map.height * MAP_GRID + 30)
	{
		j = 0;
		while (j < data->map.width * MAP_GRID && j < 500)
		{
			mlx_pixel_put(data->mlx.ptr, data->win.ptr, j, i, 0x000000);
			j++;
		}
		i++;
	}
}

static void	print_move_count(t_data *data)
{
	static unsigned int	count;
	char				num[12];

	++count;
	if (count == 0xFFFFFFFF)
		count = 0;
	get_str_from_int(count, num, 12);
	handle_write(STDOUT_FD, num);
	handle_write(STDOUT_FD, "\n");
	draw_black_bottom(data);
	mlx_string_put(
		data->mlx.ptr, data->win.ptr,
		10, data->map.height * MAP_GRID, 0xFFFFFF, num);
}

static void	move_player(t_data *data)
{
	int			temp[2];

	temp[0] = data->entity.player[0];
	temp[1] = data->entity.player[1];
	if (data->input.key[KEYCODE_W])
		temp[1]--;
	if (data->input.key[KEYCODE_A])
		temp[0]--;
	if (data->input.key[KEYCODE_S])
		temp[1]++;
	if (data->input.key[KEYCODE_D])
		temp[0]++;
	if (data->map.tile[temp[1]][temp[0]] == MAP_WALL)
		return ;
	if (data->entity.player[0] != temp[0] || data->entity.player[1] != temp[1])
	{
		data->entity.player[0] = temp[0];
		data->entity.player[1] = temp[1];
		print_move_count(data);
	}
}

void	key_event(t_data *data)
{
	move_player(data);
	if (data->input.key[KEYCODE_ESC])
		handle_exit(SUCCESS, "The program was successfully completed.\n");
}

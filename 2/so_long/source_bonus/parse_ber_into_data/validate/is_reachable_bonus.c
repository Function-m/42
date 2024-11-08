/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_reachable_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:07:27 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:21:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	dfs(t_data *data, int x, int y, char **visited)
{
	if (x < 0 || x >= data->map.width)
		return (FALSE);
	if (y < 0 || y >= data->map.height)
		return (FALSE);
	if (visited[y][x] == TRUE)
		return (FALSE);
	if (data->map.tile[y][x] == MAP_WALL)
		return (FALSE);
	if (data->map.tile[y][x] == MAP_PLAYER)
		return (TRUE);
	visited[y][x] = TRUE;
	return (dfs(data, x + 1, y, visited) || dfs(data, x - 1, y, visited)
		|| dfs(data, x, y + 1, visited) || dfs(data, x, y - 1, visited));
}

int	is_reachable(t_data *data, int x, int y)
{
	char	**visited;
	int		i;
	int		result;

	visited = handle_malloc(data->map.height * sizeof(char *));
	i = 0;
	while (i < data->map.height)
		visited[i++] = handle_malloc(data->map.width);
	result = dfs(data, x, y, visited);
	i = 0;
	while (i < data->map.height)
		handle_free(visited[i++]);
	handle_free(visited);
	return (result);
}

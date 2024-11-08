/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 07:55:39 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 02:49:22 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*skip_empty_line(char *src);
void	validate_map(char **map);
void	init_player(t_cub3d *cub3d);

static size_t	count_map_height(char *src)
{
	size_t	map_height;

	map_height = 1;
	while (*src)
	{
		if (*src == '\n')
			map_height++;
		src++;
	}
	return (map_height);
}

static size_t	count_map_width(char *src)
{
	size_t	map_width;
	size_t	temp_map_width;

	map_width = 0;
	temp_map_width = 0;
	while (*src)
	{
		if (*src == '\n')
		{
			if (map_width < temp_map_width)
				map_width = temp_map_width;
			temp_map_width = 0;
		}
		temp_map_width++;
		src++;
	}
	return (map_width);
}

static char	*strdup_until_newline(char *src, size_t map_width)
{
	size_t	len;
	char	*dst;

	len = 0;
	while (src[len] && src[len] != '\n')
		len++;
	dst = do_calloc(map_width + 1);
	ft_strncpy(dst, src, len);
	dst[len] = '\0';
	return (dst);
}

static char	**convert_src_to_map(char *src, size_t map_height, size_t map_width)
{
	size_t	i;
	char	**map;

	i = 0;
	map = do_calloc(sizeof(char *) * (map_height + 1));
	while (*src)
	{
		map[i] = strdup_until_newline(src, map_width);
		while (*src && *src != '\n')
			src++;
		if (*src == '\n')
			src++;
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	parse_map(t_cub3d *cub3d, char **src)
{
	*src = skip_empty_line(*src);
	cub3d->map.height = count_map_height(*src);
	cub3d->map.width = count_map_width(*src);
	cub3d->map.data \
		= convert_src_to_map(*src, cub3d->map.height, cub3d->map.width);
	init_player(cub3d);
	validate_map(cub3d->map.data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 05:37:49 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 02:49:22 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

#define NO	0b1
#define SO	0b10
#define WE	0b100
#define EA	0b1000
#define F	0b10000
#define C	0b100000

char	*skip_spaces(char *src);
char	*skip_empty_line(char *src);

static int	get_and_validate_color(char **src)
{
	int	color;
	int	i;

	i = 0;
	while ((*src)[i] >= '0' && (*src)[i] <= '9')
		i++;
	while (ft_isspace(((*src)[i])))
		i++;
	if (!((*src)[i] == ',' || (*src)[i] == '\n'))
	{
		write(2, ERRMSG_COLOR, sizeof(ERRMSG_COLOR) - 1);
		do_exit(EXIT_FAILURE);
	}
	color = ft_atoi(*src);
	*src = ft_strchrs(*src, ",\n");
	if (!(**src) || color < 0 || color > 255)
	{
		write(2, ERRMSG_COLOR, sizeof(ERRMSG_COLOR) - 1);
		do_exit(EXIT_FAILURE);
	}
	return (color);
}

static int	get_rgb(char **src, int *is_exist, int identifier)
{
	int	red;
	int	green;
	int	blue;

	*is_exist |= identifier;
	*src = skip_spaces(*src + 1);
	red = get_and_validate_color(src);
	*src = skip_spaces(*src);
	if (*(*src)++ != ',')
	{
		write(2, ERRMSG_COLOR, sizeof(ERRMSG_COLOR) - 1);
		do_exit(EXIT_FAILURE);
	}
	*src = skip_spaces(*src);
	green = get_and_validate_color(src);
	*src = skip_spaces(*src);
	if (*(*src)++ != ',')
	{
		write(2, ERRMSG_COLOR, sizeof(ERRMSG_COLOR) - 1);
		do_exit(EXIT_FAILURE);
	}
	*src = skip_spaces(*src);
	blue = get_and_validate_color(src);
	*src = skip_spaces(*src);
	return ((red << 16) | (green << 8) | blue);
}

static char	*get_file_path(char **src, int *is_exist, int identifier)
{
	char	*file_path;

	*src += 2;
	if (*is_exist & identifier)
	{
		write(2, ERRMSG_IDENTIFIERS, sizeof(ERRMSG_IDENTIFIERS) - 1);
		do_exit(EXIT_FAILURE);
	}
	*is_exist |= identifier;
	*src = skip_spaces(*src);
	file_path = *src;
	*src = skip_spaces(*src);
	while (**src && **src != '\n')
		(*src)++;
	**src = '\0';
	(*src)++;
	return (file_path);
}

void	parse_element(t_cub3d *cub3d, char **src)
{
	int	is_exist;

	is_exist = 0;
	while (is_exist != (NO | SO | WE | EA | F | C))
	{
		*src = skip_empty_line(*src);
		*src = skip_spaces(*src);
		if (!ft_strncmp("NO", *src, 2))
			cub3d->file_path.north = get_file_path(src, &is_exist, NO);
		else if (!ft_strncmp("SO", *src, 2))
			cub3d->file_path.south = get_file_path(src, &is_exist, SO);
		else if (!ft_strncmp("WE", *src, 2))
			cub3d->file_path.west = get_file_path(src, &is_exist, WE);
		else if (!ft_strncmp("EA", *src, 2))
			cub3d->file_path.east = get_file_path(src, &is_exist, EA);
		else if (!ft_strncmp("F", *src, 1))
					cub3d->color.floor = get_rgb(src, &is_exist, F);
		else if (!ft_strncmp("C", *src, 1))
			cub3d->color.ceiling = get_rgb(src, &is_exist, C);
		else
		{
			write(2, ERRMSG_CUB_FILE, sizeof(ERRMSG_CUB_FILE) - 1);
			do_exit(EXIT_FAILURE);
		}
	}
}

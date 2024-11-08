/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cub_into_cub3d_struct.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 04:03:29 by suham             #+#    #+#             */
/*   Updated: 2024/02/16 14:12:57 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	parse_element(t_cub3d *cub3d, char **src);
void	parse_map(t_cub3d *cub3d, char **src);

void	parse_cub_file_into_cub3d_struct(t_cub3d *cub3d, char *cub_file_path)
{
	char	*src;

	src = ft_read(cub_file_path);
	parse_element(cub3d, &src);
	parse_map(cub3d, &src);
}

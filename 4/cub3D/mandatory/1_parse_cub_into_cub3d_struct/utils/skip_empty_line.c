/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_empty_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 06:32:48 by suham             #+#    #+#             */
/*   Updated: 2024/02/03 09:49:38 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*skip_empty_line(char *src)
{
	while (*src && *src == '\n')
		src++;
	return (src);
}
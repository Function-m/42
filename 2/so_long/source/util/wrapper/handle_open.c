/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_open.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 22:01:07 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 03:07:13 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	handle_open(const char *path)
{
	int	fd;

	fd = open(path, RDONLY);
	if (fd == FAILURE)
		handle_exit(FAILURE, "'open' function failed\n");
	return (fd);
}

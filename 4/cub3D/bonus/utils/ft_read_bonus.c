/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:10:51 by suham             #+#    #+#             */
/*   Updated: 2024/02/18 02:49:22 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

char	*ft_read(char *file_name)
{
	int		fd;
	char	*buf;
	char	tmp[1000];
	size_t	size_read;
	size_t	size_buf;

	fd = do_open(file_name, O_RDONLY);
	size_buf = 1;
	while (1)
	{
		size_read = do_read(fd, tmp, 1000);
		if (size_read == 0)
			break ;
		size_buf += size_read;
	}
	do_close(fd);
	fd = do_open(file_name, O_RDONLY);
	buf = do_calloc(size_buf);
	do_read(fd, buf, size_buf);
	buf[size_buf - 1] = '\0';
	do_close(fd);
	return (buf);
}

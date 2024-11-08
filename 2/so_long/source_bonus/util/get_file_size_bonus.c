/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_size_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:34:11 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:21:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_ull	get_file_size(const char *file_path)
{
	int		fd;
	t_ull	file_size;
	char	buf_read[1024];
	int		bytes_read;

	fd = handle_open(file_path);
	file_size = 0;
	bytes_read = 0;
	while (TRUE)
	{
		bytes_read = handle_read(fd, buf_read, sizeof(buf_read));
		if (bytes_read == 0)
			break ;
		file_size += bytes_read;
	}
	handle_close(fd);
	return (file_size);
}

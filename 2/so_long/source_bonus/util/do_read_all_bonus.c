/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_read_all_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:43:08 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:24:22 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*do_read_all(const char *file_path)
{
	int		fd;
	t_ull	file_size;
	char	*content;

	file_size = get_file_size(file_path);
	if (file_size > 0xFFFFFFFF)
		handle_exit(FAILURE, "Map is too big\n");
	content = handle_malloc(file_size + 1);
	fd = handle_open(file_path);
	handle_read(fd, content, file_size);
	content[file_size] = '\0';
	handle_close(fd);
	return (content);
}

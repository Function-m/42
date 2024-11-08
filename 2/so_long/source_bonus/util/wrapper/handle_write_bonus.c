/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_write_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:12:17 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:21:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <unistd.h>

t_ll	handle_write(int fd, const char *str)
{
	t_ll	bytes_written;

	bytes_written = write(fd, str, get_str_len(str));
	if (bytes_written == FAILURE)
		handle_exit(FAILURE, "'write' function failed\n");
	return (bytes_written);
}

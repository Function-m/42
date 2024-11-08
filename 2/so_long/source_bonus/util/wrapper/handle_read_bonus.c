/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_read_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:09:08 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:21:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <unistd.h>

t_ll	handle_read(int fd, void *buf, t_ull bytes)
{
	t_ll	bytes_read;

	bytes_read = read(fd, buf, bytes);
	if (bytes_read == FAILURE)
		handle_exit(FAILURE, "'read' function failed\n");
	return (bytes_read);
}

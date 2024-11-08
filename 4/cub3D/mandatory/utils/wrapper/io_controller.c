/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_controller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:39:12 by suham             #+#    #+#             */
/*   Updated: 2024/02/15 23:07:49 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "wrapper.h"

ssize_t	do_read(int fd, void *buf, size_t count)
{
	ssize_t	result;

	result = read(fd, buf, count);
	if (result == -1)
	{
		perror("Error\nread");
		do_exit(EXIT_FAILURE);
	}
	return (result);
}

ssize_t	do_write(int fd, void *buf, size_t count)
{
	ssize_t	result;

	result = write(fd, buf, count);
	if (result == -1)
	{
		perror("Error\nwrite");
		do_exit(EXIT_FAILURE);
	}
	return (result);
}

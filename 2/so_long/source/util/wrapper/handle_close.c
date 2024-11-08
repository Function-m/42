/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:30 by suham             #+#    #+#             */
/*   Updated: 2023/11/21 03:33:01 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	handle_close(int fd)
{
	if (close(fd) == FAILURE)
		handle_exit(FAILURE, "'close' function failed\n");
}
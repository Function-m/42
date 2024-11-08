/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 03:28:53 by suham             #+#    #+#             */
/*   Updated: 2023/10/21 17:05:36 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	handle_exit(int status)
{
	if (status == ERR_ARGUMENT)
		handle_write(_STDERR_FILENO,
			"An invalid value was entered as an argument to the program.\n");
	else if (status == ERR_MALLOC)
		handle_write(_STDERR_FILENO, "Memory allocation failed.\n");
	else if (status == ERR_WRITE)
		handle_write(_STDERR_FILENO, "Failed to use the write function.\n");
	else if (status == ERR_KILL)
		handle_write(_STDERR_FILENO, "Failed to use the kill function.\n");
	exit(status);
}

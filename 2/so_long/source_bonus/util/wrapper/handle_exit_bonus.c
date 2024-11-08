/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exit_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:10:13 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:21:06 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdlib.h>

// For leak check

// void	check_leak(void)
// {
// 	system("leaks so_long");
// }
// atexit(check_leak);

void	handle_exit(int status, char *msg)
{
	if (status == FAILURE)
	{
		handle_write(STDERR_FD, PRE_ERR_MSG);
		handle_write(STDERR_FD, msg);
	}
	else
		handle_write(STDOUT_FD, msg);
	exit(status);
}

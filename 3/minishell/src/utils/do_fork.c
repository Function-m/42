/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 01:22:42 by suham             #+#    #+#             */
/*   Updated: 2024/01/24 01:59:17 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	do_fork(t_memory **memory)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Fatal Error: fork\n");
		do_exit(1, memory);
	}
	return (pid);
}

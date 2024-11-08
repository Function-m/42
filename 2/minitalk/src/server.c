/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:48:48 by suham             #+#    #+#             */
/*   Updated: 2023/10/21 17:18:17 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	print_pid(void)
{
	char	*pid;

	pid = num_to_str(getpid());
	handle_write(_STDOUT_FILENO, "Server PID: ");
	handle_write(_STDOUT_FILENO, pid);
	handle_write(_STDOUT_FILENO, "\n");
	free(pid);
}

void	handle_signal(int signum)
{
	static char			received_char = '\0';
	static int			bit_index = 0;
	static char			buffer[0xFFFFFFFF];
	static unsigned int	buf_index = 0;

	if (signum == SIGUSR1)
		received_char |= (1 << bit_index);
	if (bit_index == 7)
	{
		if (buf_index == 0xFFFFFFFF)
			handle_exit(ERR_ARGUMENT);
		buffer[buf_index ++] = received_char;
		if (received_char == '\0')
		{
			handle_write(_STDOUT_FILENO, buffer);
			buf_index = 0;
		}
		received_char = '\0';
		bit_index = 0;
	}
	else
		++ bit_index;
}

int	main(void)
{
	print_pid();
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (TRUE)
		pause();
}
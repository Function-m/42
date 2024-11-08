/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:18:02 by suham             #+#    #+#             */
/*   Updated: 2023/10/21 17:18:17 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

typedef struct s_data
{
	long long	server_pid;
	char		*message;
}				t_data;

void	send_message(t_data data)
{
	int	char_index;
	int	bit_index;

	char_index = 0;
	while (TRUE)
	{
		bit_index = 0;
		while (bit_index < 8)
		{
			if (data.message[char_index] & (1 << bit_index))
				handle_kill(data.server_pid, SIGUSR1);
			else
				handle_kill(data.server_pid, SIGUSR2);
			++ bit_index;
		}
		if (data.message[char_index ++] == '\0')
			return ;
	}
}

static t_data	initialize_data(char **argv)
{
	t_data	data;

	data.server_pid = str_to_num(argv[1]);
	data.message = argv[2];
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 3)
		handle_exit(ERR_ARGUMENT);
	data = initialize_data(argv);
	send_message(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_to_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:06:12 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/25 22:32:01 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	heredoc_to_file(t_token *head, int idx, t_memory **memory)
{
	char	*file_name;
	char	*file_idx;
	int		fd;
	t_token	*current;

	file_name = str_dup(FILE_NAME, memory);
	file_idx = str_itoa(idx, memory);
	file_name = str_join(file_name, file_idx, str_len(file_idx), memory);
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0777);
	current = head;
	while (current && current->value)
	{
		write(fd, current->value, str_len(current->value));
		write(fd, "\n", 1);
		current = current->next;
	}
	close(fd);
}

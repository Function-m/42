/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:50:01 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/24 22:29:05 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*heredoc_parsing(char *delimiter, t_memory **memory)
{
	char	*input;
	t_token	*token_head;

	token_head = NULL;
	input = NULL;
	while (TRUE)
	{
		do_free(input, memory);
		input = do_readline("> ", memory);
		if (input == NULL || !str_cmp(input, delimiter))
			return (token_head);
		token_append(&token_head, str_dup(input, memory), memory);
	}
}

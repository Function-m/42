/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_separate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:09:18 by suham             #+#    #+#             */
/*   Updated: 2024/01/22 00:12:16 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*split_at_pipe(t_token *token, t_memory **memory)
{
	t_token	*current;
	t_token	*next_start;
	t_token	*prev_end;

	current = token;
	next_start = NULL;
	while (current != NULL)
	{
		if (current->type == PIPE)
		{
			next_start = current->next;
			current->next = NULL;
			prev_end->next = NULL;
			do_free(current->value, memory);
			do_free(current, memory);
			break ;
		}
		prev_end = current;
		current = current->next;
	}
	return (next_start);
}

void	tokens_separate(t_tokens **new, t_token *token, t_memory **memory)
{
	t_token		*now_start;
	t_token		*next_start;

	now_start = token;
	while (now_start != NULL)
	{
		next_start = split_at_pipe(now_start, memory);
		tokens_append(new, now_start, memory);
		now_start = next_start;
	}
}

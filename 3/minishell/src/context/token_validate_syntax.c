/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_validate_syntax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 09:20:30 by suham             #+#    #+#             */
/*   Updated: 2024/01/26 05:48:49 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

static int	validate_quotes(t_token *current)
{
	char	*ptr;
	char	quote;

	ptr = current->value;
	quote = '\0';
	while (ptr != NULL && *ptr != '\0')
	{
		if ((*ptr == '\"' || *ptr == '\''))
		{
			if (quote == '\0')
				quote = *ptr;
			else if (quote == *ptr)
				quote = '\0';
		}
		ptr++;
	}
	return (quote == '\0');
}

static int	validate_redirection(t_token *current, t_token *next)
{
	if (current->type == HEREDOC)
	{
		if (next == NULL)
			return (FALSE);
		if (!(next->type & (HEREDOC_END | HEREDOC_END_WITH_QUOTE)))
			return (FALSE);
	}
	else if (current->type & (FILE_OUT_APPEND | FILE_IN | FILE_OUT))
	{
		if (!next || !(next->type & COMMON))
			return (FALSE);
	}
	return (TRUE);
}

static int	validate_pipe(t_token *prev, t_token *current, t_token *next)
{
	if (current->type & PIPE)
	{
		if (prev == NULL || next == NULL || prev->type & PIPE)
			return (FALSE);
	}
	return (TRUE);
}

int	token_validate_syntax(t_token *token)
{
	t_token	*prev;
	t_token	*current;
	t_token	*next;

	prev = NULL;
	current = token;
	while (current != NULL)
	{
		next = current->next;
		if (!validate_quotes(current)
			|| !validate_redirection(current, next)
			|| !validate_pipe(prev, current, next))
		{
			write(2, "Minishell: syntax error.\n", 25);
			g_exit_code = 258;
			return (FALSE);
		}
		prev = current;
		current = current->next;
	}
	return (TRUE);
}

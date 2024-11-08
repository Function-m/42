/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:49:17 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/24 17:58:39 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

static void	exec_heredoc(t_tokens *tokens_head, char **env, t_memory **memory)
{
	t_tokens	*current_tokens;
	t_token		*current_token;
	t_token		*raw_token;
	t_token		*next_token;

	current_tokens = tokens_head;
	while (current_tokens != NULL)
	{
		current_token = current_tokens->token;
		while (current_token != NULL)
		{
			if (current_token->type == HEREDOC)
			{
				next_token = current_token->next;
				raw_token = heredoc_parsing(next_token->value, memory);
				heredoc_expand(raw_token, env, next_token->type, memory);
				heredoc_to_file(raw_token, current_tokens->idx, memory);
			}
			current_token = current_token->next;
		}
		current_tokens = current_tokens->next;
	}
	do_exit(0, memory);
}

int	heredoc(t_context *context, t_memory **memory)
{
	pid_t	pid;
	int		child_status;

	pid = do_fork(memory);
	if (pid > 0)
	{
		wait(&child_status);
		if (WIFEXITED(child_status))
			g_exit_code = WEXITSTATUS(child_status);
		else
			g_exit_code = 1;
		if (g_exit_code != 0)
			return (FAILURE);
	}
	else
	{
		signal(SIGINT, sig_handler_heredoc);
		exec_heredoc(context->tokens, context->env, memory);
	}
	return (SUCCESS);
}

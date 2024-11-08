/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   excute_multi_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:19:18 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/26 11:47:46 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

void	pipe_and_execute(t_context *context, int *pids, t_memory **memory)
{
	t_tokens	*current_tokens;
	char		*cmd;
	int			idx;

	current_tokens = context->tokens;
	context->before_out_fd = 0;
	idx = 0;
	while (current_tokens != NULL)
	{
		cmd = tokens_get_cmd(current_tokens, memory);
		pipe(context->fd);
		pids[current_tokens->idx] = execute_cmd(context, cmd, idx, memory);
		context->before_out_fd = context->fd[0];
		current_tokens = current_tokens->next;
		idx++;
		do_free(cmd, memory);
	}
}

static void	child_end_check(int child_status)
{
	if (WIFEXITED(child_status))
		g_exit_code = WEXITSTATUS(child_status);
	else if (WIFSIGNALED(child_status))
	{
		if (child_status == SIGINT)
			write(2, "\n", 1);
		else if (child_status == SIGQUIT)
			write(2, "Quit: 3\n", 8);
		g_exit_code = WTERMSIG(child_status) + 128;
	}
	else
		g_exit_code = 1;
}

void	exit_child(t_context *context, int *pids, t_memory **memory)
{
	t_tokens	*current_tokens;
	char		*file_name;
	char		*file_idx;
	int			child_status;

	current_tokens = context->tokens;
	while (current_tokens != NULL)
	{
		waitpid(pids[current_tokens->idx], &child_status, 0);
		file_name = str_dup(FILE_NAME, memory);
		file_idx = str_itoa(current_tokens->idx, memory);
		file_name = str_join(file_name, file_idx, str_len(file_idx), memory);
		unlink(file_name);
		do_free(file_name, memory);
		do_free(file_idx, memory);
		current_tokens = current_tokens->next;
	}
	child_end_check(child_status);
	do_free(pids, memory);
}

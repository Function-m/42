/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:18:52 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/25 23:34:19 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

static int	set_redirect_single(t_token *head, t_memory **memory)
{
	t_token		*current_token;
	char		*file_name;
	int			res;

	current_token = head;
	while (current_token != NULL)
	{
		res = 0;
		if (current_token->type == HEREDOC)
		{
			file_name = str_join(FILE_NAME, "0", 1, memory);
			res = handle_infile_single(file_name);
			do_free(file_name, memory);
		}
		else if (current_token->type == FILE_IN)
			res = handle_infile_single(current_token->next->value);
		else if (current_token->type == FILE_OUT)
			res = handle_outfile_single(current_token->next->value);
		else if (current_token->type == FILE_OUT_APPEND)
			res = handle_outfile_append_single(current_token->next->value);
		current_token = current_token->next;
		if (res != 0)
			return (res);
	}
	return (0);
}

static void	single_builtin(
	t_context *context, char *cmd, int idx, t_memory **memory)
{
	t_exec	*exec;
	int		default_fd[2];

	exec = init_exec(context, cmd, idx, memory);
	default_fd[0] = dup(0);
	default_fd[1] = dup(1);
	if (set_redirect_single(exec->current_token, memory) == 0)
		execute_builtin(context, exec->cmds);
	do_dup2(default_fd[0], 0, "dup2 in set pipe.");
	do_dup2(default_fd[1], 1, "dup2 in set pipe.");
}

static void	check_multi(t_context *context, t_memory **memory)
{
	int		*pids;
	char	*first_cmd;

	first_cmd = tokens_get_cmd(context->tokens, memory);
	if (context->cmd_cnt == 1 && is_builtin(first_cmd))
	{
		single_builtin(context, first_cmd, 0, memory);
	}
	else
	{
		pids = do_calloc(context->cmd_cnt * sizeof(int), memory);
		pipe_and_execute(context, pids, memory);
		exit_child(context, pids, memory);
	}
}

static void	init_execution(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag |= ECHOCTL;
	tcsetattr(1, 0, &term);
}

int	execution(t_context *context, t_memory **memory)
{
	init_execution();
	context->cmd_cnt = tokens_len(context->tokens);
	check_multi(context, memory);
	return (SUCCESS);
}

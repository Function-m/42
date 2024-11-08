/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:19:22 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/26 14:09:09 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

static void	set_pipe(t_context *context, int idx)
{
	if (context->cmd_cnt > 1)
	{
		if (idx == 0)
		{
			do_dup2(context->fd[1], 1, "dup2 in set pipe.");
			close(context->fd[0]);
		}
		else if (idx == context->cmd_cnt - 1)
		{
			do_dup2(context->before_out_fd, 0, "dup2 in set pipe.");
			close(context->fd[0]);
			close(context->fd[1]);
		}
		else
		{
			do_dup2(context->before_out_fd, 0, "dup2 in set pipe.");
			do_dup2(context->fd[1], 1, "dup2 in set pipe.");
			close(context->fd[0]);
		}
	}
}

static void	set_redirect(t_token *head, int idx, t_memory **memory)
{
	t_token		*current_token;
	char		*file_name;
	char		*file_idx;

	current_token = head;
	while (current_token != NULL)
	{
		if (current_token->type == HEREDOC)
		{
			file_name = str_dup(FILE_NAME, memory);
			file_idx = str_itoa(idx, memory);
			file_name = str_join(file_name, \
			file_idx, str_len(file_idx), memory);
			handle_infile(file_name, memory);
			do_free(file_name, memory);
		}
		else if (current_token->type == FILE_IN)
			handle_infile(current_token->next->value, memory);
		else if (current_token->type == FILE_OUT)
			handle_outfile(current_token->next->value, memory);
		else if (current_token->type == FILE_OUT_APPEND)
			handle_outfile_append(current_token->next->value, memory);
		current_token = current_token->next;
	}
}

static void	execute_vector(
	t_context *context, t_exec *exec, int is_dir, t_memory **memory)
{
	if (exec->cmd == NULL)
		do_exit(0, memory);
	else if (is_builtin(exec->cmd))
	{
		execute_builtin(context, exec->cmds);
		do_exit(g_exit_code, memory);
	}
	else if (exec->p_cmd == NULL || exec->cmd[0] == '\0')
	{
		write(2, "Minishell: ", 11);
		write(2, exec->cmd, str_len(exec->cmd));
		write(2, ": command not found\n", 20);
		do_exit(127, memory);
	}
	else if (is_dir)
	{
		write(2, "Minishell: ", 11);
		write(2, exec->cmd, str_len(exec->cmd));
		write(2, ": is a directory\n", 17);
		do_exit(126, memory);
	}
	else if (execve(exec->p_cmd, exec->cmds, context->env))
		perror("Minishell");
	do_exit(1, memory);
}

static void	execute_child(t_context *context, t_exec *exec, t_memory **memory)
{
	struct stat	buf;

	set_pipe(context, exec->idx);
	set_redirect(exec->current_token, exec->idx, memory);
	stat(exec->cmd, &buf);
	execute_vector(context, exec, S_ISDIR(buf.st_mode), memory);
}

int	execute_cmd(t_context *context, char *cmd, int idx, t_memory **memory)
{
	t_exec	*exec;

	exec = init_exec(context, cmd, idx, memory);
	exec->pid = do_fork(memory);
	if (exec->pid > 0)
	{
		if (idx > 0)
			close(context->before_out_fd);
		close(context->fd[1]);
		if (idx == context->cmd_cnt - 1)
			close(context->fd[0]);
	}
	else
	{
		signal(SIGQUIT, SIG_DFL);
		signal(SIGINT, SIG_DFL);
		execute_child(context, exec, memory);
	}
	return (exec->pid);
}

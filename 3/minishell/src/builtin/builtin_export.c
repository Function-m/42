/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:24:19 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/26 12:01:52 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

static int	any_option(char **cmds)
{
	int	i;
	int	size;

	i = 0;
	size = strs_len(cmds);
	while (i < size)
	{
		if (cmds[i][0] == '-' && str_len(cmds[i]) > 1)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static void	show_export(char **env, t_memory **memory)
{
	int		i;
	int		size;
	int		key_len;
	char	**sorted;

	i = 0;
	sorted = env_sort(env, memory);
	size = strs_len(sorted);
	while (i < size)
	{
		key_len = str_len_until_chr(sorted[i], '=');
		write(1, "declare -x ", 11);
		write(1, sorted[i], key_len);
		if (*str_find_chr(sorted[i], "=") == '=')
		{
			write(1, "\"", 1);
			write(1, sorted[i] + key_len, str_len(sorted[i] + key_len));
			write(1, "\"\n", 2);
		}
		else
			write(1, "\n", 1);
		i++;
	}
	do_free(sorted, memory);
}

static int	valid_env_char(char target)
{
	if (target >= '0' && target <= '9')
		return (TRUE);
	else if (target >= 'a' && target <= 'z')
		return (TRUE);
	else if (target >= 'A' && target <= 'Z')
		return (TRUE);
	else if (target == '_')
		return (TRUE);
	else
		return (FALSE);
}

static int	valid_key(char *cmd)
{
	int		i;
	int		len;

	i = 0;
	len = str_len(cmd);
	if ((cmd[0] >= '0' && cmd[0] <= '9') || cmd[0] == '=')
	{
		write(2, "Minishell: export: `", 20);
		write(2, cmd, str_len(cmd));
		write(2, "': not a valid identifier\n", 26);
		return (FALSE);
	}
	while (i < len && cmd[i] != '=')
	{
		if (valid_env_char(cmd[i]) == FALSE)
		{
			write(2, "Minishell: export: `", 20);
			write(2, cmd, str_len(cmd));
			write(2, "': not a valid identifier\n", 26);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

void	builtin_export(t_context *context, char **cmds)
{
	int		cnt_cmds;
	int		i;

	g_exit_code = 0;
	cnt_cmds = strs_len(cmds);
	i = 1;
	if (any_option(cmds))
	{
		write(2, "Minishell: export: options are not allowed\n", 43);
		g_exit_code = 1;
	}
	else if (cnt_cmds < 2)
		show_export(context->env, &context->memory);
	else
	{
		while (i < cnt_cmds)
		{
			if (cmds[i] != NULL && cmds[i][0] != '\0' && valid_key(cmds[i]))
				context->env = \
				env_update(cmds[i], context->env, &context->memory);
			else
				g_exit_code = 1;
			i++;
		}
	}
}

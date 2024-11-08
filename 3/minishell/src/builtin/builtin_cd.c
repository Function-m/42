/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:15:57 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/26 15:15:52 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

static int	any_option(char **cmds)
{
	int	idx;
	int	size;

	idx = 1;
	size = strs_len(cmds);
	while (idx < size)
	{
		if (str_len(cmds[idx]) > 1 && cmds[idx][0] == '-'
			&& cmds[idx][1] != '-')
			return (1);
		idx++;
	}
	return (0);
}

static char	*get_target_pwd(
	t_context *context, char *target, char *tmp, t_memory **memory)
{
	if (target == NULL || str_cmp(target, "--") == 0)
	{
		tmp = env_get_value("HOME", context->env, memory);
		if (tmp == NULL)
			print_error("Minishell: cd: HOME not set\n", 1);
	}
	else if (target[0] == '\0')
		tmp = getcwd(NULL, 0);
	else if (target[0] == '~')
	{
		tmp = env_get_value("HOME", context->env, memory);
		if (tmp == NULL)
			tmp = context->home;
		tmp = str_join(tmp, target + 1, str_len(target + 1), memory);
	}
	else if (target[0] == '-')
	{
		tmp = env_get_value("OLDPWD", context->env, memory);
		if (tmp == NULL)
			print_error("Minishell: cd: OLDPWD not set\n", 1);
		else
			printf("%s\n", tmp);
	}
	return (tmp);
}

static void	success(
	t_context *context, char *pwd, char *oldpwd, t_memory **memory)
{
	char	*current;
	char	*env_pwd;
	char	*env_oldpwd;

	chdir(pwd);
	current = getcwd(NULL, 0);
	env_pwd = "PWD=";
	env_pwd = str_join(env_pwd, current, str_len(current), memory);
	context->env = env_update(env_pwd, context->env, memory);
	env_oldpwd = "OLDPWD=";
	env_oldpwd = str_join(env_oldpwd, oldpwd, str_len(oldpwd), memory);
	context->env = env_update(env_oldpwd, context->env, memory);
}

static void	error(int option, int accessable, char *target, int is_dir)
{
	write(2, "Minishell: cd: ", 15);
	if (option == 1)
	{
		write(2, "options are not allowed\n", 24);
	}
	else if (accessable == 0 && is_dir == FALSE)
	{
		write(2, target, str_len(target));
		write(2, ": Not a directory\n", 18);
	}
	else
	{
		write(2, target, str_len(target));
		write(2, ": No such file or directory\n", 28);
	}
	g_exit_code = 1;
}

void	builtin_cd(t_context *context, char **cmds)
{
	int			option;
	int			accessable;
	char		*pwd;
	char		*oldpwd;
	struct stat	buf;

	g_exit_code = 0;
	option = any_option(cmds);
	oldpwd = getcwd(NULL, 0);
	pwd = get_target_pwd(context, cmds[1], str_dup(cmds[1], \
	&context->memory), &context->memory);
	accessable = access(pwd, R_OK);
	stat(pwd, &buf);
	if (option == 0 && accessable == 0 && S_ISDIR(buf.st_mode))
		success(context, pwd, oldpwd, &context->memory);
	else if (pwd != NULL)
		error(option, accessable, cmds[1], S_ISDIR(buf.st_mode));
}

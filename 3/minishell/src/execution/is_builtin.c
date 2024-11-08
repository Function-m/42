/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:25:07 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/24 14:27:02 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define NUM_BUILTINS 7

int	is_builtin(char *cmd)
{
	size_t		i;
	const char	*builtins[NUM_BUILTINS] = {
		"cd", "echo", "env", "exit", "export", "pwd", "unset"};

	if (cmd != NULL)
	{
		i = 0;
		while (i < NUM_BUILTINS)
		{
			if (!str_cmp(cmd, (char *)builtins[i]))
				return (TRUE);
			i++;
		}
	}
	return (FALSE);
}

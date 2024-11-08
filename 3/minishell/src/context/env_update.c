/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:28:23 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 06:55:57 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_update(char *src, char **env, t_memory **memory)
{
	size_t	key_len;
	char	*key;
	char	*target;

	key_len = str_len_until_chr(src, '=');
	if (*str_find_chr(src, "=") == '=')
		key_len--;
	key = str_dup_by_n(src, key_len, memory);
	target = env_find(key, env, memory);
	do_free(key, memory);
	if (target
		&& *str_find_chr(src, "=") == '\0' && *str_find_chr(target, "=") == '=')
		return (env);
	else
	{
		env = strs_remove(env, target, memory);
		env = strs_append(env, src, memory);
	}
	return (env);
}

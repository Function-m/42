/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:10:51 by suham             #+#    #+#             */
/*   Updated: 2024/01/26 15:05:25 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

static char	*extract_env_key(char **ptr, t_memory **memory)
{
	char	*end;

	end = *ptr;
	if (!((*end >= 'A' && *end <= 'Z') || (*end >= 'a' && *end <= 'z') || \
	*end == '_'))
		return (NULL);
	while ((*end >= 'A' && *end <= 'Z') || (*end >= 'a' && *end <= 'z')
		|| (*end >= '0' && *end <= '9') || (*end == '_'))
		end++;
	return (str_dup_by_n(*ptr, end - *ptr, memory));
}

void	env_expand(char **new, char **ptr, char **env, t_memory **memory)
{
	char	*key;
	char	*value;

	(*ptr)++;
	if (**ptr == '?')
	{
		value = str_itoa(g_exit_code, memory);
		*new = str_join(*new, value, str_len(value), memory);
		do_free(value, memory);
		(*ptr)++;
	}
	else if (!((**ptr >= 'A' && **ptr <= 'Z') \
		|| (**ptr >= 'a' && **ptr <= 'z') || **ptr == '_'))
		*new = str_join(*new, "$", 1, memory);
	else
	{
		key = extract_env_key(ptr, memory);
		if (key == NULL)
			return ;
		value = env_get_value(key, env, memory);
		if (value != NULL)
			*new = str_join(*new, value, str_len(value), memory);
		*ptr += str_len(key);
		do_free(key, memory);
	}
}

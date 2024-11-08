/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:36:42 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/25 04:58:40 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_get_value(char *key, char **env, t_memory **memory)
{
	char	*env_address;
	char	*equal_chr;
	char	*key_with_equal;

	key_with_equal = str_dup(key, memory);
	env_address = env_find(key_with_equal, env, memory);
	if (env_address)
	{
		equal_chr = str_find_chr(env_address, "=");
		if (*equal_chr == '\0')
			return (do_calloc(1, memory));
		else
			return (str_dup(equal_chr + 1, memory));
	}
	return (NULL);
}

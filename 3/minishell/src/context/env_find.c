/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:28:33 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 06:55:46 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_find(char *key, char **env, t_memory **memory)
{
	size_t	key_len;
	size_t	cmp_key_len;
	char	*cmp_key;

	key_len = str_len(key);
	while (*env != NULL)
	{
		cmp_key_len = str_len_until_chr(*env, '=');
		if (*str_find_chr(*env, "=") == '=')
			cmp_key_len--;
		cmp_key = str_dup_by_n(*env, cmp_key_len, memory);
		if (!str_cmp(cmp_key, key))
			return (*env);
		env++;
	}
	return (NULL);
}

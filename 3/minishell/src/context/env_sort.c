/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:33:44 by suham             #+#    #+#             */
/*   Updated: 2024/01/24 16:38:22 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_sort(char **env, t_memory **memory)
{
	int		i;
	int		j;
	char	*temp;
	char	**new_env;

	if (env == NULL || *env == NULL)
		return (NULL);
	i = 0;
	new_env = strs_dup(env, memory);
	while (new_env[i] != NULL)
	{
		j = i + 1;
		while (new_env[j] != NULL)
		{
			if (str_cmp(new_env[i], new_env[j]) > 0)
			{
				temp = new_env[i];
				new_env[i] = new_env[j];
				new_env[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (new_env);
}

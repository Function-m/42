/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:23:43 by junsbae           #+#    #+#             */
/*   Updated: 2024/01/25 05:00:42 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_delete(char *key, char **env, t_memory **memory)
{
	char	*target;

	target = env_find(key, env, memory);
	env = strs_remove(env, target, memory);
	return (env);
}

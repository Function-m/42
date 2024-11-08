/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_tokens_as_cmd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 01:50:06 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 22:15:30 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_tokens_as_cmd(t_context *context)
{
	if (heredoc(context, &context->memory) == FAILURE)
		return (FAILURE);
	if (execution(context, &context->memory) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:35:21 by suham             #+#    #+#             */
/*   Updated: 2024/01/18 22:41:13 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_type(char *value, int prev_type)
{
	if (!str_cmp_by_n("<<", value, 2))
		return (HEREDOC);
	if (!str_cmp_by_n(">>", value, 2))
		return (FILE_OUT_APPEND);
	if (!str_cmp_by_n("<", value, 1))
		return (FILE_IN);
	if (!str_cmp_by_n(">", value, 1))
		return (FILE_OUT);
	if (!str_cmp_by_n("|", value, 1))
		return (PIPE);
	if (prev_type == HEREDOC)
	{
		if (*(str_find_chr(value, "\'\"")) != '\0')
			return (HEREDOC_END_WITH_QUOTE);
		else
			return (HEREDOC_END);
	}
	return (COMMON);
}

void	token_assign_type(t_token *head)
{
	int		prev_type;
	t_token	*current;

	prev_type = COMMON;
	current = head;
	while (current != NULL)
	{
		current->type = get_type(current->value, prev_type);
		prev_type = current->type;
		current = current->next;
	}
}

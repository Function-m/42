/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 03:53:27 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 21:32:58 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_new_len(char *ptr)
{
	char	*start;

	start = ptr;
	if (!str_cmp_by_n(ptr, "<<", 2) || !str_cmp_by_n(ptr, ">>", 2))
		return (2);
	else if (*ptr == '<' || *ptr == '>' || *ptr == '|')
		return (1);
	while (*ptr != '\0' && *ptr != '<' && *ptr != '>' \
	&& *ptr != '|' && *ptr != ' ' && *ptr != '\t' && *ptr != '\n')
	{
		if (*ptr == '"' || *ptr == '\'')
			ptr += str_len_until_chr(ptr + 1, *ptr);
		ptr++;
	}
	return (ptr - start);
}

void	tokenize_str(t_token **head, char *str, t_memory **memory)
{
	size_t	new_len;
	char	*new;
	char	*ptr;

	if (str == NULL)
		return ;
	*head = NULL;
	ptr = str;
	while (*ptr != '\0')
	{
		while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n')
			ptr++;
		new_len = get_new_len(ptr);
		new = str_dup_by_n(ptr, new_len, memory);
		token_append(head, new, memory);
		ptr += new_len;
	}
}

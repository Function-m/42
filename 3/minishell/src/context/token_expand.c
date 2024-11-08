/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:35:44 by suham             #+#    #+#             */
/*   Updated: 2024/01/26 12:20:19 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

static void	process_quote(char **new, char **ptr, char **env, t_memory **memory)
{
	char	*start;
	char	quote_chr;

	quote_chr = **ptr;
	(*ptr)++;
	start = *ptr;
	while (**ptr && **ptr != quote_chr)
	{
		if (quote_chr == '\"' && **ptr == '$')
		{
			*new = str_join(*new, start, *ptr - start, memory);
			env_expand(new, ptr, env, memory);
			start = *ptr;
			continue ;
		}
		(*ptr)++;
	}
	*new = str_join(*new, start, *ptr - start, memory);
	if (*new == NULL)
		*new = str_dup("", memory);
	(*ptr)++;
}

static void	process_unquote(char **new, char **ptr, t_memory **memory)
{
	char	*start;

	start = *ptr;
	while (**ptr && **ptr != '\'' && **ptr != '\"' && **ptr != '$')
		(*ptr)++;
	*new = str_join(*new, start, *ptr - start, memory);
}

static void	handle_env_expansion(
	char **new, char **ptr, char **env, t_memory **memory)
{
	char	*expanded_env;

	expanded_env = NULL;
	env_expand(&expanded_env, ptr, env, memory);
	*new = expanded_env;
}

static void	insert_tokens(
	t_token **current, char **new, char **expanded_env, t_memory **memory)
{
	char	*start;
	char	*end;

	start = *expanded_env;
	while (start && *start)
	{
		end = start;
		while (*end && *end != ' ' && *end != '\t' && *end != '\n')
			end++;
		*new = str_join(*new, start, end - start, memory);
		if (*end == ' ' || *end == '\t' || *end == '\n')
		{
			if (*new)
			{
				token_append(current, (*current)->value, memory);
				(*current)->value = *new;
				*new = NULL;
				*current = (*current)->next;
			}
			while (*end && (*end == ' ' || *end == '\t' || *end == '\n'))
				end++;
		}
		start = end;
	}
	do_free(*expanded_env, memory);
}

void	token_expand(t_token *head, char **env, t_memory **memory)
{
	char	*new;
	char	*expanded_env;
	char	*ptr;

	while (head != NULL)
	{
		new = NULL;
		ptr = head->value;
		while (*ptr)
		{
			if (*ptr == '\'' || *ptr == '\"')
				process_quote(&new, &ptr, env, memory);
			else if (*ptr == '$')
			{
				handle_env_expansion(&expanded_env, &ptr, env, memory);
				insert_tokens(&head, &new, &expanded_env, memory);
			}
			else
				process_unquote(&new, &ptr, memory);
		}
		do_free(head->value, memory);
		head->value = new;
		head = head->next;
	}
}

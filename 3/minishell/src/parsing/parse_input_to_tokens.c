/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_to_tokens.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:29:49 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 21:02:01 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_parsing(t_context *context)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	do_free(context->raw_token, &context->memory);
	do_free(context->tokens, &context->memory);
	context->raw_token = NULL;
	context->tokens = NULL;
}

int	parse_input_to_tokens(t_context *context)
{
	init_parsing(context);
	tokenize_str(&context->raw_token, context->input, &context->memory);
	token_assign_type(context->raw_token);
	if (token_validate_syntax(context->raw_token) == FALSE)
		return (FAILURE);
	token_expand(context->raw_token, context->env, &context->memory);
	tokens_separate(&context->tokens, context->raw_token, &context->memory);
	return (SUCCESS);
}

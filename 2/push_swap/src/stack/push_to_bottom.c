/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_bottom.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 03:36:30 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 08:43:21 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push_to_bottom(t_stack *stack, int content)
{
	t_stack_element	*new_element;

	new_element = handle_malloc(1, sizeof(t_stack_element));
	new_element->content = content;
	new_element->index = NO_INDEX;
	new_element->up = stack->bottom;
	new_element->down = _NULL;
	if (stack->bottom)
		stack->bottom->down = new_element;
	stack->bottom = new_element;
	if (stack->size == 0)
		stack->top = new_element;
	++(stack->size);
}

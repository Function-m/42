/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:44:09 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 09:06:30 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int	reverse_rotate(t_stack *stack)
{
	t_stack_element	*origin_bottom;
	t_stack_element	*new_bottom;

	if (stack->size < 2)
		return (FALSE);
	origin_bottom = stack->bottom;
	new_bottom = stack->bottom->up;
	new_bottom->down = _NULL;
	stack->top->up = origin_bottom;
	origin_bottom->down = stack->top;
	origin_bottom->up = _NULL;
	stack->top = origin_bottom;
	stack->bottom = new_bottom;
	return (TRUE);
}

void	rra(t_stack *a)
{
	if (reverse_rotate(a))
		print_with_delay(RRA);
}

void	rrb(t_stack *b)
{
	if (reverse_rotate(b))
		print_with_delay(RRB);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

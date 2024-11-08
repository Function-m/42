/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:44:09 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 16:53:03 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_bonus.h"

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
	reverse_rotate(a);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}

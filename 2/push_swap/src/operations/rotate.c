/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:44:09 by suham             #+#    #+#             */
/*   Updated: 2023/10/26 23:07:13 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int	rotate(t_stack *stack)
{
	t_stack_element	*top;

	if (stack->size < 2)
		return (FALSE);
	top = stack->top;
	stack->top = top->down;
	stack->top->up = _NULL;
	top->down = _NULL;
	top->up = stack->bottom;
	stack->bottom->down = top;
	stack->bottom = top;
	return (TRUE);
}

void	ra(t_stack *a)
{
	if (rotate(a))
		print_with_delay(RA);
}

void	rb(t_stack *b)
{
	if (rotate(b))
		print_with_delay(RB);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

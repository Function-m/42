/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:44:09 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 16:53:26 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_bonus.h"

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
	rotate(a);
}

void	rb(t_stack *b)
{
	rotate(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

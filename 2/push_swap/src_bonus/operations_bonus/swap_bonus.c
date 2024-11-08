/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:44:09 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 16:53:46 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_bonus.h"

static int	swap(t_stack *stack)
{
	t_stack_element	*first;
	t_stack_element	*second;

	if (stack->size < 2)
		return (FALSE);
	first = stack->top;
	second = stack->top->down;
	first->down = second->down;
	first->up = second;
	second->down = first;
	second->up = _NULL;
	stack->top = second;
	if (first->down)
		first->down->up = first;
	if (stack->bottom == second)
		stack->bottom = first;
	return (TRUE);
}

void	sa(t_stack *a)
{
	swap(a);
}

void	sb(t_stack *b)
{
	swap(b);
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

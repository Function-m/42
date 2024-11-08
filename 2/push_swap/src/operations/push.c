/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 04:44:09 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 09:20:02 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static int	push(t_stack *dest, t_stack *src)
{
	t_stack_element	*target;

	if (src->size == 0)
		return (FALSE);
	target = src->top;
	src->top = src->top->down;
	if (src->top)
		src->top->up = _NULL;
	src->size--;
	if (src->size == 0)
		src->bottom = _NULL;
	target->down = dest->top;
	target->up = _NULL;
	if (dest->top)
		dest->top->up = target;
	dest->top = target;
	dest->size++;
	if (dest->size == 1)
		dest->bottom = target;
	return (TRUE);
}

void	pa(t_stack *a, t_stack *b)
{
	if (push(a, b))
		print_with_delay(PA);
}

void	pb(t_stack *a, t_stack *b)
{
	if (push(b, a))
		print_with_delay(PB);
}

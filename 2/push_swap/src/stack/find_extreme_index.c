/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_extreme_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:41:50 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 08:50:53 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	find_extreme_index(t_stack *stack, int (*compare)(int, int))
{
	t_stack_element	*current;
	int				extreme_index;

	if (!stack || !stack->top)
		return (NO_INDEX);
	current = stack->top;
	extreme_index = current->index;
	while (current)
	{
		if (compare(current->index, extreme_index))
			extreme_index = current->index;
		current = current->down;
	}
	return (extreme_index);
}

static int	is_greater(int one, int two)
{
	return (one > two);
}

static int	is_smaller(int one, int two)
{
	return (one < two);
}

int	find_highest_index(t_stack *stack)
{
	return (find_extreme_index(stack, is_greater));
}

int	find_lowest_index(t_stack *stack)
{
	return (find_extreme_index(stack, is_smaller));
}

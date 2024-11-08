/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_by_ascending_content.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 03:36:30 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 08:45:07 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	index_by_ascending_content(t_stack *stack)
{
	t_stack_element	*current;
	t_stack_element	*min_content;
	int				i;

	i = 1;
	while (i <= stack->size)
	{
		current = stack->top;
		min_content = _NULL;
		while (current)
		{
			if (current->index == NO_INDEX && (min_content == _NULL
					|| current->content <= min_content->content))
				min_content = current;
			current = current->down;
		}
		if (min_content != _NULL)
			min_content->index = i;
		++i;
	}
}

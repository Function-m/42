/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:38:38 by suham             #+#    #+#             */
/*   Updated: 2023/10/31 11:05:50 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	is_sorted(t_stack *a, t_stack *b)
{
	t_stack_element	*current;

	if (b->size != 0)
		return (FALSE);
	if (a->size < 2)
		return (TRUE);
	current = a->top;
	while (current->down)
	{
		if (current->index + 1 != current->down->index)
			return (FALSE);
		current = current->down;
	}
	return (TRUE);
}

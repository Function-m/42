/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:47:14 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 08:53:31 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_small(t_stack *a, t_stack *b)
{
	int	a_highest_index;

	a_highest_index = find_highest_index(a);
	if (a->size == 3 && a->top->index == a_highest_index)
		ra(a);
	else if (a->size == 3 && a->top->down->index == a_highest_index)
		rra(a);
	if (a->size == 3 && a->top->index > a->top->down->index)
		sa(a);
	if (!is_sorted(a, b) && a->size == 2)
		sa(a);
}

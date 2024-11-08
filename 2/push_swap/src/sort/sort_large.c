/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 23:16:12 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 10:07:37 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	rotate_a_sorted(t_stack *a)
{
	while (a->top->index != 1)
	{
		if (a->top->index > a->size / 2)
			ra(a);
		else
			rra(a);
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	push_all_expect_three_to_b(a, b, a->size / 2, a->size / 4);
	sort_small(a, b);
	push_all_to_be_sorted_on_a(a, b);
	rotate_a_sorted(a);
}

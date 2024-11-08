/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_to_be_sorted_on_a.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:49:08 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 09:30:53 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

typedef struct s_cost_data
{
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		total;
}			t_cost_data;

typedef struct s_cost
{
	t_cost_data	current;
	t_cost_data	min;
}			t_cost;

void	find_min_cost(t_cost *cost, t_stack *a, t_stack *b);

static void	move_by_cost(t_cost_data *cost, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while ((cost->ra <= cost->rra && i < cost->ra)
		|| (cost->rb <= cost->rrb && i < cost->rb))
	{
		if (cost->ra <= cost->rra && i < cost->ra)
			ra(a);
		if (cost->rb <= cost->rrb && i < cost->rb)
			rb(b);
		++i;
	}
	i = 0;
	while ((cost->rra < cost->ra && i < cost->rra)
		|| (cost->rrb < cost->rb && i < cost->rrb))
	{
		if (cost->rra < cost->ra && i < cost->rra)
			rra(a);
		if (cost->rrb < cost->rb && i < cost->rrb)
			rrb(b);
		++i;
	}
}

void	push_all_to_be_sorted_on_a(t_stack *a, t_stack *b)
{
	t_cost	cost;

	while (b->size > 0)
	{
		find_min_cost(&cost, a, b);
		move_by_cost(&(cost.min), a, b);
		pa(a, b);
	}
}

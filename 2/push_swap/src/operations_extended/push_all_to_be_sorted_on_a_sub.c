/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_to_be_sorted_on_a_sub.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:49:08 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 09:25:20 by suham            ###   ########.fr       */
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

static void	get_b_cost(t_cost *cost, t_stack *b)
{
	static int	current_cost = 0;

	cost->current.rb = current_cost;
	cost->current.rrb = b->size - current_cost;
	if (++current_cost == b->size)
		current_cost = 0;
}

static void	get_a_cost(t_cost *cost, t_stack *a, t_stack_element *current_b)
{
	t_stack_element	*current_a;
	int				highest_index;
	int				lowest_index;
	int				prev_index;

	highest_index = find_highest_index(a);
	lowest_index = find_lowest_index(a);
	cost->current.ra = 0;
	cost->current.rra = a->size;
	prev_index = a->bottom->index;
	current_a = a->top;
	while (1)
	{
		if (prev_index < current_b->index
			&& current_b->index < current_a->index)
			return ;
		if (current_a->index == lowest_index
			&& (current_b->index > highest_index
				|| current_b->index < lowest_index))
			return ;
		cost->current.ra++;
		cost->current.rra--;
		prev_index = current_a->index;
		current_a = current_a->down;
	}
}

static void	get_total_cost(t_cost *cost)
{
	if (cost->current.ra <= cost->current.rra)
	{
		if (cost->current.rb <= cost->current.rrb)
		{
			if (cost->current.ra < cost->current.rb)
				cost->current.total = cost->current.rb;
			else
				cost->current.total = cost->current.ra;
		}
		else
			cost->current.total = cost->current.ra + cost->current.rrb;
	}
	else
	{
		if (cost->current.rrb < cost->current.rb)
		{
			if (cost->current.rra < cost->current.rrb)
				cost->current.total = cost->current.rrb;
			else
				cost->current.total = cost->current.rra;
		}
		else
			cost->current.total = cost->current.rra + cost->current.rb;
	}
}

static void	change_min_cost(t_cost *cost)
{
	if (cost->min.total > cost->current.total)
		cost->min = cost->current;
}

void	find_min_cost(t_cost *cost, t_stack *a, t_stack *b)
{
	t_stack_element	*current_b;

	cost->min.total = _INT_MAX;
	current_b = b->top;
	while (current_b)
	{
		get_b_cost(cost, b);
		get_a_cost(cost, a, current_b);
		get_total_cost(cost);
		change_min_cost(cost);
		current_b = current_b->down;
	}
}

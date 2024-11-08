/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_all_expect_three_to_b.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:28:47 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 10:35:44 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

typedef struct s_chunk_info
{
	int	size;
	int	upper_count;
	int	lower_count;
	int	upper_multiplier;
	int	lower_multiplier;
}	t_chunk_info;

void	push_to_b(t_stack *a, t_stack *b, int mid_index, t_chunk_info *data)
{
	if (a->top->index >= mid_index
		&& a->top->index <= mid_index + data->size * data->upper_multiplier)
	{
		pb(a, b);
		data->upper_count++;
	}
	else if (a->top->index <= mid_index
		&& a->top->index >= mid_index - data->size * data->lower_multiplier)
	{
		pb(a, b);
		rb(b);
		data->lower_count++;
	}
	else
		ra(a);
}

void	push_all_expect_three_to_b(
	t_stack *a, t_stack *b, int mid_index, int chunk_size)
{
	t_chunk_info	chunk;

	if (chunk_size < 10)
		chunk.size = 10;
	else
		chunk.size = chunk_size;
	chunk.upper_multiplier = 1;
	chunk.upper_count = 0;
	chunk.lower_multiplier = 1;
	chunk.lower_count = 0;
	while (a->size > 3)
	{
		push_to_b(a, b, mid_index, &chunk);
		if (chunk.upper_count == chunk.size)
		{
			chunk.upper_multiplier++;
			chunk.upper_count = 0;
		}
		if (chunk.lower_count == chunk.size)
		{
			chunk.lower_multiplier++;
			chunk.lower_count = 0;
		}
	}
}

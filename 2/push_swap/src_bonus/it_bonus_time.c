/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it_bonus_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:55:10 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 17:20:09 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_bonus.h"
#include "utils_bonus.h"
#include "sort_bonus.h"

#define TERRIBLE_ERROR	-999

static int	read_operation(char *new_operation)
{
	t_ll	read_size;

	read_size = read(0, new_operation, 3);
	if (read_size == -1)
		handle_exit(TERRIBLE_ERROR);
	if (read_size == 0)
		return (FALSE);
	if (new_operation[2] == '\n')
	{
		new_operation[2] = '\0';
		return (TRUE);
	}
	read_size = read(0, new_operation + 3, 1);
	if (read_size == -1)
		handle_exit(TERRIBLE_ERROR);
	if (new_operation[3] == '\n')
	{
		new_operation[3] = '\0';
		return (TRUE);
	}
	else
		handle_exit(TERRIBLE_ERROR);
	return (TRUE);
}

static void	do_operation(char *operation, t_stack *a, t_stack *b)
{
	if (is_same_str("sa", operation))
		sa(a);
	else if (is_same_str("sb", operation))
		sb(b);
	else if (is_same_str("ss", operation))
		ss(a, b);
	else if (is_same_str("ra", operation))
		ra(a);
	else if (is_same_str("rb", operation))
		rb(b);
	else if (is_same_str("rr", operation))
		rr(a, b);
	else if (is_same_str("rra", operation))
		rra(a);
	else if (is_same_str("rrb", operation))
		rrb(b);
	else if (is_same_str("rrr", operation))
		rrr(a, b);
	else if (is_same_str("pa", operation))
		pa(a, b);
	else if (is_same_str("pb", operation))
		pb(a, b);
	else
		handle_exit(TERRIBLE_ERROR);
}

void	its_bonus_time(t_stack *a, t_stack *b)
{
	char	operation[4];

	while (read_operation(operation))
		do_operation(operation, a, b);
	if (is_sorted(a, b))
		handle_write(_STDOUT_FILENO, "OK\n", 3);
	else
		handle_write(_STDOUT_FILENO, "KO\n", 3);
}

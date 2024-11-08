/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:47:53 by suham             #+#    #+#             */
/*   Updated: 2023/10/31 06:20:54 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	print_operation(int print_code)
{
	if (print_code == NONE)
		return ;
	else if (print_code == SA)
		handle_write(_STDOUT_FILENO, "sa", 2);
	else if (print_code == SB)
		handle_write(_STDOUT_FILENO, "sb", 2);
	else if (print_code == SS)
		handle_write(_STDOUT_FILENO, "ss", 2);
	else if (print_code == PA)
		handle_write(_STDOUT_FILENO, "pa", 2);
	else if (print_code == PB)
		handle_write(_STDOUT_FILENO, "pb", 2);
	else if (print_code == RA)
		handle_write(_STDOUT_FILENO, "ra", 2);
	else if (print_code == RB)
		handle_write(_STDOUT_FILENO, "rb", 2);
	else if (print_code == RR)
		handle_write(_STDOUT_FILENO, "rr", 2);
	else if (print_code == RRA)
		handle_write(_STDOUT_FILENO, "rra", 3);
	else if (print_code == RRB)
		handle_write(_STDOUT_FILENO, "rrb", 3);
	else if (print_code == RRR)
		handle_write(_STDOUT_FILENO, "rrr", 3);
	handle_write(_STDOUT_FILENO, "\n", 1);
}

void	print_with_delay(int print_code)
{
	static int	delayed_print_code = NONE;

	if ((print_code == SA && delayed_print_code == SB)
		|| (print_code == SB && delayed_print_code == SA))
		delayed_print_code = SS;
	else if ((print_code == RA && delayed_print_code == RB)
		|| (print_code == RB && delayed_print_code == RA))
		delayed_print_code = RR;
	else if ((print_code == RRA && delayed_print_code == RRB)
		|| (print_code == RRB && delayed_print_code == RRA))
		delayed_print_code = RRR;
	else if ((print_code == PA && delayed_print_code == PB)
		|| (print_code == PB && delayed_print_code == PA))
		delayed_print_code = NONE;
	else if ((print_code == RA && delayed_print_code == RRA)
		|| (print_code == RRA && delayed_print_code == RA))
		delayed_print_code = NONE;
	else if ((print_code == RB && delayed_print_code == RRB)
		|| (print_code == RRB && delayed_print_code == RB))
		delayed_print_code = NONE;
	else
	{
		print_operation(delayed_print_code);
		delayed_print_code = print_code;
	}
}

void	print_remaining(void)
{
	print_with_delay(NONE);
}

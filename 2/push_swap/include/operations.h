/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 05:16:17 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 10:05:05 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "utils.h"
# include "stack.h"

// Print code
# define NONE	-1
# define SA		0
# define SB 	1
# define SS 	2
# define PA 	3
# define PB 	4
# define RA 	5
# define RB 	6
# define RR 	7
# define RRA 	8
# define RRB 	9
# define RRR 	10

// Swap
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// Push
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

// Rotate
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);

// Reverse rotate
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// Print
void	print_with_delay(int print_code);
void	print_remaining(void);

// Operations extended
void	push_all_to_be_sorted_on_a(t_stack *a, t_stack *b);
void	push_all_expect_three_to_b(
			t_stack *a, t_stack *b, int mid_index, int chunk_size);

#endif

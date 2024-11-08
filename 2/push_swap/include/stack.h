/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:54:12 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 09:17:12 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "utils.h"

# define NO_INDEX 0

typedef struct s_stack_element
{
	int						content;
	int						index;
	struct s_stack_element	*down;
	struct s_stack_element	*up;
}	t_stack_element;

typedef struct s_stack
{
	t_stack_element			*top;
	t_stack_element			*bottom;
	int						size;
}	t_stack;

t_stack						init_stack(void);
void						push_to_bottom(t_stack *stack, int content);
void						index_by_ascending_content(t_stack *stack);
int							find_highest_index(t_stack *stack);
int							find_lowest_index(t_stack *stack);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:37:43 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 09:04:34 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "utils.h"
# include "stack.h"
# include "operations.h"

int		is_sorted(t_stack *a, t_stack *b);
void	sort_stacks(t_stack *a, t_stack *b);

// Sub functions for sort_stacks
void	sort_small(t_stack *a, t_stack *b);
void	sort_large(t_stack *a, t_stack *b);

#endif
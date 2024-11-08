/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 22:36:34 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 10:16:29 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_stacks(t_stack *a, t_stack *b)
{
	if (is_sorted(a, b))
		handle_exit(0);
	if (a->size <= 3)
		sort_small(a, b);
	else
		sort_large(a, b);
	if (!is_sorted(a, b))
		handle_exit(ERR_SORT_FAILED);
}

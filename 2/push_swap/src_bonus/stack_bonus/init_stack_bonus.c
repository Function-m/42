/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 03:36:30 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 12:10:51 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_bonus.h"

t_stack	init_stack(void)
{
	t_stack	new_stack;

	new_stack.top = _NULL;
	new_stack.bottom = _NULL;
	new_stack.size = 0;
	return (new_stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsbae <junsbae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:36:08 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 22:27:57 by junsbae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	reverse_str(char *new)
{
	int		len;
	int		i;
	char	temp;

	len = str_len(new);
	i = 0;
	while (i < len / 2)
	{
		temp = new[i];
		new[i] = new[len - i - 1];
		new[len - i - 1] = temp;
		i++;
	}
}

static void	int_to_str(int num, char *new)
{
	int	i;
	int	is_negative;

	if (num < 0)
	{
		is_negative = TRUE;
		num = -num;
	}
	else
		is_negative = FALSE;
	i = 0;
	while (num > 0)
	{
		new[i++] = (num % 10) + '0';
		num /= 10;
	}
	if (is_negative)
		new[i++] = '-';
	new[i] = '\0';
}

char	*str_itoa(int num, t_memory **memory)
{
	char	temp[12];
	char	*new;

	if (num == 0)
		return ("0");
	else
		int_to_str(num, temp);
	new = do_calloc(str_len(temp) + 1, memory);
	str_cpy(new, temp);
	reverse_str(new);
	return (new);
}

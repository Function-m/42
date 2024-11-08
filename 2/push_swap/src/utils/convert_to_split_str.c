/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_split_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:46:30 by suham             #+#    #+#             */
/*   Updated: 2023/10/25 18:31:21 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	count_words(char *str, int delimiter)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = FALSE;
	while (*str)
	{
		if (*str == delimiter)
			in_word = FALSE;
		else if (in_word == FALSE)
		{
			in_word = TRUE;
			++count;
		}
		++str;
	}
	return (count);
}

static char	*copy_str(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

char	**convert_to_split_str(char *str, int delimiter)
{
	char	**result;
	int		word_count;
	int		i;
	int		j;
	int		k;

	word_count = count_words(str, delimiter);
	result = handle_malloc(word_count + 1, sizeof(char *));
	i = 0;
	j = 0;
	while (i < word_count)
	{
		while (str[j] == delimiter)
			++j;
		k = 0;
		while (str[j + k] && str[j + k] != delimiter)
			++k;
		result[i] = handle_malloc(k + 1, sizeof(char));
		copy_str(result[i], str + j, k);
		j += k;
		++i;
	}
	result[i] = _NULL;
	return (result);
}

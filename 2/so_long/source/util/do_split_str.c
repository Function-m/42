/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:31:13 by suham             #+#    #+#             */
/*   Updated: 2023/11/24 07:53:24 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_segments_and_nullify_delimiters(char *text, char delimiter)
{
	int	segment_count;
	int	i;
	int	is_segment;

	segment_count = 0;
	i = 0;
	is_segment = TRUE;
	while (text[i])
	{
		if (text[i] == delimiter)
		{
			text[i] = '\0';
			is_segment = TRUE;
		}
		else if (is_segment)
		{
			++segment_count;
			is_segment = FALSE;
		}
		++i;
	}
	return (segment_count + is_segment);
}

void	populate_segment_pointers(
	char **segment_pointers, char *text, int total_segments, int total_len)
{
	int	current_segment;
	int	i;

	current_segment = 0;
	i = 0;
	while (i < total_len && current_segment < total_segments)
	{
		segment_pointers[current_segment++] = &text[i];
		while (i < total_len && text[i])
			++i;
		++i;
	}
	segment_pointers[current_segment] = NULL_PTR;
}

char	**do_split_str(char *str, char delimiter)
{
	int		total_segments;
	char	**segment_pointers;
	int		total_len;

	total_len = get_str_len(str);
	total_segments = count_segments_and_nullify_delimiters(str, delimiter);
	segment_pointers = handle_malloc((total_segments + 1) * sizeof(char *));
	populate_segment_pointers(segment_pointers, str, total_segments, total_len);
	return (segment_pointers);
}

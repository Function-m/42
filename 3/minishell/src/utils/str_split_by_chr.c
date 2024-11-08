/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split_by_chr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 21:34:57 by suham             #+#    #+#             */
/*   Updated: 2024/01/25 21:35:12 by suham            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_size(char const *str, char c)
{
	int		i;
	int		size;

	size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] && str[i] == c)
				i++;
		}
		else
		{
			size++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (size);
}

static void	make_arr(int *arr, char const *str, char c)
{
	int		i;
	int		idx;
	int		flag;

	idx = 0;
	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] && str[i] == c)
				i++;
			if (flag)
				idx++;
		}
		else
		{
			arr[idx]++;
			i++;
			flag = 1;
		}
	}
}

static void	insert_arr(char **ans, char const *str, char c, int cnt)
{
	int		i;
	int		idx;
	int		flag;

	i = 0;
	idx = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			while (str[i] && str[i] == c)
				i++;
			if (flag)
				idx++;
			cnt = 0;
		}
		else
		{
			ans[idx][cnt++] = str[i];
			i++;
			flag = 1;
		}
	}
}

char	**str_split_by_chr(char *str, char chr, t_memory **memory)
{
	int		size;
	char	**ans;
	int		*arr;
	int		i;

	size = check_size(str, chr);
	ans = do_calloc(sizeof(char *) * (size + 1), memory);
	ans[size] = 0;
	arr = do_calloc(sizeof(int) * size, memory);
	i = 0;
	while (i < size)
		arr[i++] = 0;
	make_arr(arr, str, chr);
	i = 0;
	while (i < size)
	{
		ans[i] = do_calloc(sizeof(char) * (arr[i] + 1), memory);
		ans[i][arr[i]] = '\0';
		i++;
	}
	insert_arr(ans, str, chr, 0);
	do_free(arr, memory);
	return (ans);
}

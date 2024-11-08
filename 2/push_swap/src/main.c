/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suham <suham@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 22:31:47 by suham             #+#    #+#             */
/*   Updated: 2023/11/01 11:19:09 by suham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "utils.h"
#include "sort.h"

static void	check_duplicate(t_stack *a)
{
	t_stack_element	*outer;
	t_stack_element	*inner;

	outer = a->top;
	while (outer != _NULL)
	{
		inner = outer->down;
		while (inner != _NULL)
		{
			if (outer->content == inner->content)
				handle_exit(ERR_INVALID_ARGUMENT);
			inner = inner->down;
		}
		outer = outer->down;
	}
}

static void	parse_and_validate_input(int argc, char **argv, t_stack *a)
{
	char	**split_str;
	int		parsed_int;
	int		i;

	i = 1;
	if (argc < 2)
		handle_exit(0);
	while (i < argc)
	{
		++i;
		++argv;
		split_str = convert_to_split_str(*argv, ' ');
		if (argc != 2 && *split_str == _NULL)
			handle_exit(ERR_INVALID_ARGUMENT);
		while (*split_str != _NULL)
		{
			parsed_int = convert_str_to_int(*split_str);
			push_to_bottom(a, parsed_int);
			++split_str;
		}
	}
	if (a->size <= 1)
		handle_exit(0);
	check_duplicate(a);
}

static void	initialize(t_stack *a, t_stack *b)
{
	*a = init_stack();
	*b = init_stack();
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	initialize(&a, &b);
	parse_and_validate_input(argc, argv, &a);
	index_by_ascending_content(&a);
	sort_stacks(&a, &b);
	print_remaining();
	handle_exit(0);
}

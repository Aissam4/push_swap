/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:35:44 by mbari             #+#    #+#             */
/*   Updated: 2021/12/18 00:09:19 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_select_instruction(char *line, t_stack *a, t_stack *b)
{
	if (!ft_memcmp(line, "sa", 2))
		swap(a, 0);
	else if (!ft_memcmp(line, "rra", 3))
		reverse_rotate_a(a, 0);
	else if (!ft_memcmp(line, "rrb", 3))
		reverse_rotate_b(b, 0);
	else if (!ft_memcmp(line, "ra", 2))
		rotate_a(a, 0);
	else if (!ft_memcmp(line, "rb", 2))
		rotate_b(b, 0);
	else if (!ft_memcmp(line, "pa", 2))
		push_a(a, b, 0);
	else if (!ft_memcmp(line, "pb", 2))
		push_b(a, b, 0);
	else
		error_msg();
}

int	main(int ac, char **av)
{
	char		*line;
	t_stack		stack_a;
	t_stack		stack_b;
	char		*string;
	int			ret;

	ac--;
	if (ac == 0)
		return (0);
	string = argv_to_string(av);
	ft_store_numbers(string, &stack_a, &stack_b);
	line = NULL;
	ret = 0;
	if (ft_issorted(&stack_a))
		exit(0);
	while ((line = get_next_line(0)))
	{
		ft_select_instruction(line, &stack_a, &stack_b);
		if (ft_issorted(&stack_a) == 1)
		{
			write(1, "OK\n", 3);
			break;
		}
		free(line);
	}
	free(line);
	if (!ft_issorted(&stack_a))
		write(1, "KO\n", 3);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 09:35:44 by mbari             #+#    #+#             */
/*   Updated: 2021/12/18 01:10:06 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_select_instruction(char *line, t_stack *a, t_stack *b)
{
	if (!ft_memcmp(line, "sa", 2) || !ft_memcmp(line, "ss", 2))
		swap(a, 0);
	else if (!ft_memcmp(line, "sb", 2) || !ft_memcmp(line, "ss", 2))
		swap(b, 0);
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
	else if (!ft_memcmp(line, "rr", 2))
		rotate_a_b(a, b);
	else if (!ft_memcmp(line, "rrr", 2))
		reverse_rotate_a_b(a, b);
	else
		error_msg();
}

int	main(int ac, char **av)
{
	char		*line;
	t_stack		stack_a;
	t_stack		stack_b;
	char		*string;

	if (ac == 1)
		return (0);
	string = argv_to_string(av);
	ft_store_numbers(string, &stack_a, &stack_b);
	if (ft_issorted(&stack_a))
		exit(0);
	line = get_next_line(0);
	while (line)
	{
		ft_select_instruction(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
		if (line[0] == '\n')
			break ;
	}
	free(line);
	if (ft_issorted(&stack_a) && !stack_b.used_size)
		write(1, "\033[32mOK\n", 11);
	else
		return (write(1, "\033[0;31mKO\n", 33), 0);
}

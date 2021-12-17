/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:23:55 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/17 23:55:04 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char		*string;
	t_stack		stack_a;
	t_stack		stack_b;

	if (argc == 1)
		return (0);
	string = argv_to_string(argv);
	ft_store_numbers(string, &stack_a, &stack_b);
	if (stack_a.size == 2)
		sort_2(&stack_a);
	else if (stack_a.size == 3)
		sort_3(&stack_a);
	else if (stack_a.size == 4 || stack_a.size == 5)
		sort_5(&stack_a, &stack_b);
	else if (stack_a.size > 5 && stack_a.size <= 10)
		sort_10(&stack_a, &stack_b);
	else if (stack_a.size > 10 && stack_a.size <= 100)
		sort_100(&stack_a, &stack_b);
	else if (stack_a.size > 100)
		sort_500(&stack_a, &stack_b);
	return (free(stack_b.array), free(stack_a.array), 0);
}
// leaks
// info struct unuesd
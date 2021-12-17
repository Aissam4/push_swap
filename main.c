/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:23:55 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/17 15:17:55 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char	**stacks_init(char *string, s_stack *a, s_stack *b)
{
	int		size;
	char	**numbers;

	numbers = ft_split(string, ' ');
	size = ft_count_numbers(string);
	a->array = (int *)malloc(sizeof(int) * size);
	b->array = (int *)malloc(sizeof(int) * size);
	a->size = size;
	b->size = size;
	a->used_size = 0;
	b->used_size = 0;
	free (string);
	return (numbers);
}

void	ft_store_numbers(char *string, s_stack *a, s_stack *b)
{
	char		**numbers;
	long long	number;
	int			i;

	i = 0;
	numbers = stacks_init(string, a, b);
	while (numbers[i])
	{
		if (!ft_isnumber(numbers[i]))
			error_msg();
		number = ft_atoi(numbers[i]);
		if (number < -2147483648 || number > 2147483647)
			error_msg();
		a->array[i] = number;
		a->used_size++;
		free(numbers[i]);
		i++;
	}
	duplicate_nambers(a);
	free(numbers);
}

int	main(int argc, char **argv)
{
    s_swap		info;
	s_stack	stack_a;
	s_stack	stack_b;
    char	*string;
	if (argc == 1)
        error_msg();
	info.size = argc - 1;
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
	else if (stack_a.size > 10)
		sort_100(&stack_a, &stack_b);
	else if (stack_a.size > 100)
		sort_500(&stack_a, &stack_b);
	free(info.array);
	free(stack_b.array);
	free(stack_a.array);
	// while (1)
	// {
	// 	printf(" ");
	// }
	return (0);
}

// leaks
// finish the project
// norminette
// optimize code
// bonus
// finish*******
// middle chunk
//sa | sb
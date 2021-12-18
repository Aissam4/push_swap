/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:24:51 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/18 01:07:28 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**stacks_init(char *string, t_stack *a, t_stack *b)
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

void	ft_store_numbers(char *string, t_stack *a, t_stack *b)
{
	char		**numbers;
	long long	number;
	int			len;
	int			i;

	numbers = stacks_init(string, a, b);
	i = 0;
	len = 0;
	while (numbers[len])
		len++;
	while (i < len)
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

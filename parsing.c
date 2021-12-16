/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:47:16 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/15 13:48:03 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_check(char *s)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			i++;
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int    *convert_args(int argc, char **argv)
{
    int     		count;
	long long int	test;
    int				argv_count;
	int     		*array;

    count = 0;
	argv_count = 0;
    array = (int *)malloc(sizeof(int) * argc);
	while (argv[++argv_count])
    {
		if (!int_check(argv[argv_count]))
		{
			error_msg();
			free(array);
			exit(EXIT_FAILURE);
		}
        test = ft_atoi(argv[argv_count]);
		if (test > INT_MAX || test  < INT_MIN)
		{
			error_msg();
			free(array);
			exit(EXIT_FAILURE);
		}
		array[count] = (int)test;
		count++;
    }
	return (array);
}

int		check_duplicated(int size, int *array, int number)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] == number)
			return (1);
		i++;
	}
	return (0);
}

void		duplicate_nambers(s_swap *stack)
{
	int	i;
	int	j;
	int	*number;
	int	size = stack->size;

	number = (int *)malloc(sizeof(int) * size);
	if (!number)
		return ;
	number[0] = stack->array[0];
	i = 1;
	j = 1;
	while (i < stack->size)
	{
		number[j] = stack->array[i];
		j++;
		if (check_duplicated(j, number, stack->array[i]))
		{
			free(stack->array);
			free(stack);
			error_msg();
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	sorted_stack(s_swap *stack)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while ((stack->array[i] < stack->array[i + 1]) && i < stack->size - 1)
		i++;
	if (i == stack->size - 1)
	{
		// free(stack->array);
		// free(stack);
		exit(EXIT_FAILURE);
	}
}
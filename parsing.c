/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:47:16 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/17 16:21:35 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*argv_to_string(char **av)
{
	char	*string;
	char	*tmp;
	int		i;

	i = 1;
	string = (char *)malloc(1);
	while (av[i])
	{
		tmp = ft_strjoin(string, av[i]);
		string = ft_strjoin(tmp, " ");
		i++;
	}
	return (string);
}

int	check_duplicated(int size, int *array, int number)
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

void	duplicate_nambers(t_stack *stack)
{
	int	i;
	int	j;
	int	*number;
	int	size;

	size = stack->size;
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
			error_msg();
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '-')
		i++;
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_numbers(char *string)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == ' ')
		{
			if (string[i + 1] == ' ')
			{
				while (string[i] == ' ')
					i++;
			}
			count++;
		}
		i++;
	}
	return (count);
}

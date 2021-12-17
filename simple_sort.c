/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:06:04 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/18 00:00:49 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ptr(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*simple_sort(t_stack *stack)
{
	int		*sorted;
	int		i;
	int		j;
	int		min_val;

	sorted = (int *)malloc(sizeof(int) * stack->size);
	i = 0;
	j = 0;
	ft_memmove(sorted, stack->array, stack->size);
	while (i < stack->size - 1)
	{
		min_val = i;
		j = i + 1;
		while (j < stack->size)
		{
			if (sorted[j] < sorted[min_val])
				min_val = j;
			j++;
		}
		swap_ptr(&sorted[min_val], &sorted[i]);
		i++;
	}
	return (sorted);
}

int	search_for_index(t_stack *stack, int key)
{
	int	i;

	i = 0;
	while (i < stack->used_size)
	{
		if (stack->array[i] <= key)
			return (i);
		i++;
	}
	return (-1);
}

void	push_to_top(t_stack *stack, int index)
{
	int	div;

	div = stack->used_size / 2;
	while (index != 0)
	{
		if (index <= div)
		{
			rotate_a(stack, 1);
			index--;
		}
		else
		{
			reverse_rotate_a(stack, 1);
			index++;
			if (index == stack->used_size)
				break ;
		}
	}
}

void	find_index_push(t_stack *a, t_stack *b, int key)
{
	int	index;

	index = search_for_index(a, key);
	while (index != -1)
	{
		push_to_top(a, index);
		push_b(a, b, 1);
		index = search_for_index(a, key);
	}
}

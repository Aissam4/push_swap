/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:06:04 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/15 00:29:45 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ptr(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	search_for_index(s_stack *stack, int key)
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

int		*simple_sort(s_stack *stack)
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

void	push_to_top(s_stack *stack, int index)
{
	while (index != 0)
	{
		if (index <= stack->used_size / 2)
		{
			rotate(stack);
			index--;
		}
		else
		{
			reverse_rotate(stack);
			index++;
			if (index == stack->used_size)
				break ;
		}
	}
}

void	find_index_push(s_stack *a, s_stack *b, int key)
{
	int index;

	index = search_for_index(a, key);
	while (index != -1)
	{
		push_to_top(a, index);
		push_b(a,b);
		index = search_for_index(a, key);
	}
}

int		max_value(s_stack *stack)
{
	int	i;
	int	index;

	i = 0;
	index = i;
	while (i < stack->used_size)
	{
		if (stack->array[index] < stack->array[i])
			index = i;
		i++;
	}
	return (index);
}

void	find_max_value(s_stack *stack)
{
	int	index;

	index = max_value(stack);
	while (index != 0)
	{
		if (index <= (stack->used_size / 2))
			rotate_b(stack);
		else
			reverse_rotate_b(stack);
		index = max_value(stack);
	}
}


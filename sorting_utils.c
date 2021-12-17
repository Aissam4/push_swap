/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:28:47 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/18 00:01:36 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack *stack)
{
	int	used_size;

	used_size = stack->used_size;
	while (used_size > 0)
	{
		stack->array[used_size] = stack->array[used_size - 1];
		used_size--;
	}
}

void	pop_stack(t_stack *stack)
{
	int	i;
	int	used_size;

	i = 0;
	used_size = stack->used_size - 1;
	while (i < used_size)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
}

int	min_value(t_stack *stack)
{
	int	i;
	int	s_index;

	i = 0;
	s_index = i;
	while (i < stack->used_size)
	{
		if (stack->array[s_index] > stack->array[i])
			s_index = i;
		i++;
	}
	return (s_index);
}

void	find_smallest_number(t_stack *stack, int i)
{
	int	s_index;

	s_index = min_value(stack);
	while (s_index != 0)
	{
		if (s_index <= i)
			rotate_a(stack, 1);
		else
			reverse_rotate_a(stack, 1);
		s_index = min_value(stack);
	}
}

int	ft_issorted(t_stack *stack)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = stack->array;
	while (i < stack->used_size -1)
	{
		if (tmp[i] > tmp[i + 1])
			return (0);
		i++;
	}
	return (1);
}

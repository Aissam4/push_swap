/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:44:54 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/18 00:02:18 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack)
{
	if (stack->array[0] > stack->array[1])
		swap(stack, 1);
}

void	sort_3(t_stack *stack)
{
	if (stack->array[0] > stack->array[1] && \
	stack->array[0] < stack->array[2] && stack->array[1] < stack->array[2])
		swap(stack, 1);
	else if (stack->array[0] > stack->array[1] && \
	stack->array[1] > stack->array[2])
	{
		swap(stack, 1);
		reverse_rotate_a(stack, 1);
	}
	else if (stack->array[0] > stack->array[1] && \
	stack->array[0] > stack->array[2] && stack->array[1] < stack->array[2])
		rotate_a(stack, 1);
	else if (stack->array[0] < stack->array[1] && \
	stack->array[1] > stack->array[2] && stack->array[0] < stack->array[2])
	{
		swap(stack, 1);
		rotate_a(stack, 1);
	}
	else if (stack->array[0] < stack->array[1] && \
	stack->array[1] > stack->array[2] && stack->array[0] > stack->array[2])
		reverse_rotate_a(stack, 1);
}

void	sort_5(t_stack *stack, t_stack *b)
{
	int	i;

	i = 0;
	if (!ft_issorted(stack))
	{
		if (stack->used_size == 5)
		{
			find_smallest_number(stack, 2);
			push_b(stack, b, 1);
			i++;
		}
		if (stack->used_size == 4)
		{
			find_smallest_number(stack, 2);
			push_b(stack, b, 1);
			i++;
		}
		sort_3(stack);
		while (i > 0)
		{
			push_a(stack, b, 1);
			i--;
		}
	}
}

void	sort_10(t_stack *a, t_stack *b)
{
	if (!ft_issorted(a))
	{
		while (a->used_size != 5)
		{
			find_smallest_number(a, 5);
			push_b(a, b, 1);
		}
		sort_5(a, b);
		while (a->used_size != a->size)
			push_a(a, b, 1);
	}
}

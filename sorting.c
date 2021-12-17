/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:44:54 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/17 08:13:58 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(s_stack *stack)
{
	if (stack->array[0] > stack->array[1])
		swap(stack);
}

void	sort_3(s_stack *stack)
{
	if (stack->array[0] > stack->array[1] && stack->array[0] < stack->array[2] && stack->array[1] < stack->array[2])
		swap(stack);
	else if (stack->array[0] > stack->array[1] && stack->array[1] > stack->array[2])
	{
		swap(stack);
		reverse_rotate_a(stack);
	}
	else if(stack->array[0] > stack->array[1] && stack->array[0] > stack->array[2] && stack->array[1] < stack->array[2])
		rotate_a(stack);
	else if (stack->array[0] < stack->array[1] && stack->array[1] > stack->array[2] && stack->array[0] < stack->array[2])
	{
		swap(stack);
		rotate_a(stack);
	}
	else if (stack->array[0] < stack->array[1] && stack->array[1] > stack->array[2] && stack->array[0] > stack->array[2])
		reverse_rotate_a(stack);
}

void	sort_5(s_stack *stack, s_stack *b)
{
	int	i;

	i = 0;
	if (!ft_issorted(stack))
	{
		if (stack->used_size == 5)
		{
			find_smallest_number(stack, 2);
			push_b(stack, b);
			i++;
		}
		if (stack->used_size == 4)
		{
			find_smallest_number(stack, 2);
			push_b(stack, b);
			i++;
		}
		sort_3(stack);
		while (i > 0)
		{
			push_a(stack, b);
			i--;
		}
	}
}

void	sort_10(s_stack *a, s_stack *b)
{
	if (!ft_issorted(a))
	{
		while (a->used_size != 5)
		{
			find_smallest_number(a, 5);
			push_b(a, b);
		}
		sort_5(a, b);
		while (a->used_size != a->size)
			push_a(a,b);
	}
}
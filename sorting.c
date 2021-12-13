/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:44:54 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/13 12:38:51 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_2(s_stack *stack)
{
	if (stack->array[0] > stack->array[1])
		swap(stack);
}

void		sort_3(s_stack *stack)
{
	if (stack->array[0] > stack->array[1] && stack->array[0] < stack->array[2] && stack->array[1] < stack->array[2])
		swap(stack);
	else if (stack->array[0] > stack->array[1] && stack->array[1] > stack->array[2])
	{
		swap(stack);
		reverse_rotate(stack);
	}
	else if(stack->array[0] > stack->array[1] && stack->array[0] > stack->array[2] && stack->array[1] < stack->array[2])
		rotate(stack);
	else if (stack->array[0] < stack->array[1] && stack->array[1] > stack->array[2] && stack->array[0] < stack->array[2])
	{
		swap(stack);
		rotate(stack);
	}
	else if (stack->array[0] < stack->array[1] && stack->array[1] > stack->array[2] && stack->array[0] > stack->array[2])
		reverse_rotate(stack);
}

void	sort_5(s_stack *stack, s_stack *b)
{
	int	i;

	i = 0;
	if (!ft_issorted(stack))
	{
		if (stack->used_size == 5)
		{
			find_smallest_number(stack);
			push_b(stack, b);
			i++;
		}
		if (stack->used_size == 4)
		{
			find_smallest_number(stack);
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

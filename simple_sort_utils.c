/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:26:47 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/15 13:28:10 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

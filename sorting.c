/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:44:54 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/15 06:19:45 by abarchil         ###   ########.fr       */
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

/*****/
void	sort_rest(s_stack *a, s_stack *b)
{
	int size;

	size = a->used_size;
	if (!ft_issorted(a))
	{
		while (a->used_size >= 5)
		{
			find_smallest_number(a, 5);
			push_b(a, b);
		}
		sort_5(a, b);
		while (a->used_size != size)
			push_a(a, b);
	}
}

void	sort_remainder(s_stack *a, s_stack *b)
{
	if (a->used_size == 2)
	{
		if (!ft_issorted(a))
			sort_2(a);
	}
	if (a->used_size == 3)
		sort_3(a);
	if (a->used_size == 5 || a->used_size == 4)
		sort_5(a, b);
	if(a->used_size > 5)
		sort_10(a, b);
		//sort_rest
}

void	sort_remainder_2(s_stack *a, s_stack *b)
{
	if (a->used_size == 2)
	{
		if (!ft_issorted(a))
			sort_2(a);
	}
	if (a->used_size == 3)
		sort_3(a);
	if (a->used_size == 5 || a->used_size == 4)
		sort_5(a, b);
	if(a->used_size > 5 && a->used_size <= 10)
		sort_10(a, b);
	if (a->used_size > 10)
		sort_100(a, b);
}

void	sort_100(s_stack *a, s_stack *b)
{
	int		*sorted;
	int		i;
	int		key;

	i = 1;
	sorted = simple_sort(a);
	while (i != 4)
	{
		key = sorted[(a->size * i) / 4];
		find_index_push(a, b, key);
		i++;
	}
	free(sorted);
	sort_remainder(a, b);
	while (b->used_size != 0)
	{
		find_max_value(b);
		push_a(a,b);
	}
}
void	sort_500(s_stack *a, s_stack *b)
{
	int		*sorted;
	int		i;
	int		key;

	i = 1;
	sorted = simple_sort(a);
	while (i != 8)
	{
		key = sorted[(a->size * i) / 8];
		find_index_push(a, b, key);
		i++;
	}
	free(sorted);
	sort_remainder_2(a, b);
	while (b->used_size != 0)
	{
		find_max_value(b);
		push_a(a,b);
	}
}
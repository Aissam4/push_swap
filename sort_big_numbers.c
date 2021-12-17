/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:21:01 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/17 15:31:23 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_rest_num(s_stack *a, s_stack *b)
{
	int	size;

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
			swap(a);
	}
	else if (a->used_size == 3)
		sort_3(a);
	else if (a->used_size == 5 || a->used_size == 4)
		sort_5(a, b);
	else if(a->used_size > 5)
		sort_100(a, b);
}

void	sort_100(s_stack *a, s_stack *b)
{
	int		*sorted;
	int		i;
	int		key;

	i = 1;
	sorted = simple_sort(a);
	while (i != 25)
	{
		key = sorted[(a->size * i) / 25];
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

void	sort_remainder_2(s_stack *a, s_stack *b)
{
	if (a->used_size == 2)
	{
		if (!ft_issorted(a))
			swap(a);
	}
	else if (a->used_size == 3)
		sort_3(a);
	else if (a->used_size == 5 || a->used_size == 4)
		sort_5(a, b);
	else if(a->used_size > 5 && a->used_size <= 10)
		sort_100(a, b);
	else if (a->used_size > 10)
		sort_100(a ,b);
}

void	sort_500(s_stack *a, s_stack *b)
{
	int		*sorted;
	int		i;
	int		key;

	i = 0;
	sorted = simple_sort(a);
	while (i != 5)
	{
		key = sorted[(a->size * i) / 5];
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

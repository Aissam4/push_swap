/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:15:58 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/15 12:16:48 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(s_stack *b)
{
	int	tmp;

	tmp = b->array[0];
	pop_stack(b);
	b->array[b->used_size - 1] = tmp;
	ft_putstr("rb\n");
}

void	reverse_rotate_b(s_stack *b)
{
	int	tmp;

	tmp = b->array[b->used_size - 1];
	push_stack(b);
	b->array[0] = tmp;
	ft_putstr("rrb\n");
}

void	push_b(s_stack *a, s_stack *b)
{
	int	used_size_b;
	int	used_size_a;
	int	i;

	i = 0;
	used_size_b = b->used_size;
	used_size_a = a->used_size;
	if (used_size_a == 0)
		return ;
	if (used_size_b == 0)
		b->array[0] = a->array[0];
	else
	{
		push_stack(b);
		b->array[0] = a->array[0];
	}
	pop_stack(a);
	b->used_size++;
	a->used_size--;
	ft_putstr("pb\n");
}

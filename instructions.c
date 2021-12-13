/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:31:43 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/13 12:32:36 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(s_stack *stack)
{
	int	tmp;

	tmp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = tmp;
	ft_putstr("sa\n");
}

void	rotate(s_stack *stack)
{
	int	tmp;

	tmp = stack->array[0];
	pop_stack(stack);
	stack->array[stack->used_size - 1] = tmp;
	ft_putstr("ra\n");
}

void	reverse_rotate(s_stack *stack)
{
	int	tmp;

	tmp = stack->array[stack->used_size - 1];
	push_stack(stack);
	stack->array[0] = tmp;
	ft_putstr("rra\n");
}

void	push_a(s_stack *a, s_stack *b)
{
	int	used_size_b;
	int	used_size_a;
	int	i;

	i = 0;
	used_size_b = b->used_size;
	used_size_a = a->used_size;
	if (used_size_b == 0)
		return ;
	if (used_size_a == 0)
		a->array[0] = b->array[0];
	else
	{
		push_stack(a);
		a->array[0] = b->array[0];
	}
	pop_stack(b);
	a->used_size++;
	b->used_size--;
	ft_putstr("pa\n");
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

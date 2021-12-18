/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:31:43 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/18 00:32:57 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack, int print)
{
	int	tmp;

	tmp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = tmp;
	if (print == 1)
		ft_putstr("sa\n");
}

void	rotate_a(t_stack *stack, int print)
{
	int	tmp;

	tmp = stack->array[0];
	pop_stack(stack);
	stack->array[stack->used_size - 1] = tmp;
	if (print == 1)
		ft_putstr("ra\n");
}

void	reverse_rotate_a(t_stack *stack, int print)
{
	int	tmp;

	tmp = stack->array[stack->used_size - 1];
	push_stack(stack);
	stack->array[0] = tmp;
	if (print == 1)
		ft_putstr("rra\n");
}

void	push_a(t_stack *a, t_stack *b, int print)
{
	int	used_size_b;
	int	used_size_a;
	int	i;

	i = 0;
	used_size_b = b->used_size;
	used_size_a = a->used_size;
	if (print == 1)
		ft_putstr("pa\n");
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
}

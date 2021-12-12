/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:44:54 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/11 10:14:44 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void		swap(s_swap *swap)
{
	int	tmp;

	tmp = swap->array[0];
	swap->array[0] = swap->array[1];
	swap->array[1] = tmp;
}

void	push_stack(s_stack *stack)
{
	int	size;

	size = stack->used_size;
	while (size > 0)
	{
		stack->array[size] = stack->array[size - 1];
		size--;
	}
}

void	pull_stack(s_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->used_size)
	{
		stack->array[i] = stack->array[i + 1];
		i++;
	}
}

void	push_b(s_stack *a, s_stack *b)
{
	if (a->used_size == 0)
		return ;
	if (b->used_size == 0)
		b->array[0] = a->array[0];
	else
	{
		push_stack(a);
		b->array[0] = a->array[0];
	}
	pull_stack(a);
	a->used_size -= 1;
	b->used_size += 1;
}


void	push_a(s_stack *a, s_stack *b)
{
	if (b->used_size == 0)
		return ;
	if (a->used_size == 0)
		a->array[0] = b->array[0];
	else
	{
		push_stack(b);
		a->array[0] = b->array[0];
	}
	pull_stack(b);
	a->used_size += 1;
	b->used_size -= 1;
}

void	reverse_rotate(s_swap *reverse_rotate)
{
	int	tmp;
	int	size;
	
	int		i;
	i = 0;
	size = reverse_rotate->size - 1;
	while (size > 0)
	{
		tmp = reverse_rotate->array[size - 1];
		reverse_rotate->array[size - 1] = reverse_rotate->array[size];
		reverse_rotate->array[size] = tmp;
		size--;
	}
}

void	rotate(s_swap *rotate)
{
	int	tmp;
	int	size;
	int i;
	
	size = rotate->size - 1;
	i = 0;
	while (i < size)
	{
		tmp = rotate->array[i];
		rotate->array[i] = rotate->array[i + 1];
		rotate->array[i + 1] = tmp;
		i++;
	}
}

void		sort_2(s_swap *sorting)
{
	if (sorting->array[0] > sorting->array[1])
	{
		ft_putstr("sa\n");
		swap(sorting);
	}

}

void		sort_3(s_swap *sorting)
{
	if (sorting->array[0] > sorting->array[1] && sorting->array[0] < sorting->array[2] && sorting->array[1] < sorting->array[2])
	{
		swap(sorting);
		ft_putstr("sa\n");
	}
	else if (sorting->array[0] > sorting->array[1] && sorting->array[1] > sorting->array[2])
	{
		swap(sorting);
		reverse_rotate(sorting);
		ft_putstr("sa\nrra\n");
	}
	else if(sorting->array[0] > sorting->array[1] && sorting->array[0] > sorting->array[2] && sorting->array[1] < sorting->array[2])
	{
		rotate(sorting);
		ft_putstr("ra\n");
	}
	else if (sorting->array[0] < sorting->array[1] && sorting->array[1] > sorting->array[2] && sorting->array[0] < sorting->array[2])
	{
		swap(sorting);
		rotate(sorting);
		ft_putstr("sa\nra\n");
	}
	else if (sorting->array[0] < sorting->array[1] && sorting->array[1] > sorting->array[2] && sorting->array[0] > sorting->array[2])
	{
		reverse_rotate(sorting);
		ft_putstr("rra\n");
	}  
}
/****/

int		min_value(int	*array, int size)
{
	int	i;
	int	min;

	i = 1;
	min = array[0];
	while (i < size)
	{
		if (min > array[i])
			min = array[i];
		i++;
	}
	return (min);
}

void	ft_find_smallest_number(s_stack *a)
{
	int	s_index;

	s_index = min_value(a->array, a->used_size);
	while (s_index != 0)
	{
		if (s_index <= 2)
			rotate(&stacks->stack_a, YES);
		else
			ft_reverse_rotate_a(&stacks->stack_a, YES);
		s_index = ft_get_smallest_index(&stacks->stack_a);
	}
}
void	sort_5(s_stack *a, s_stack *b)
{
	int	i;

	i = 0;
	if (a.used_size == 5)
	{
		ft_find_smallest_number(a);
		ft_push_b(a);
		i++;
	}
	if (a.used_size == 4)
	{
		ft_find_smallest_number(a);
		ft_push_b(a);
		i++;
	}
	sort_3((s_swap *)a);
	while (i > 0)
	{
		push_a(b);
		i--;
	}
}
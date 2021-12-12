/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:44:54 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/12 23:36:17 by abarchil         ###   ########.fr       */
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
	int	used_size_b;
	int	used_size_a;
	int	i;

	i = 0;
	used_size_b = b->used_size;
	used_size_a = a->used_size;
	ft_putstr("pb\n");
	if (used_size_a == 0)
		return ;
	if (used_size_b == 0)
		b->array[0] = a->array[0];
	else
	{
		push_stack(b);
		b->array[0] = a->array[0];
	}
	pull_stack(a);
	b->used_size++;
	a->used_size--;
}

void	push_a(s_stack *a, s_stack *b)
{
	int	used_size_b;
	int	used_size_a;
	int	i;

	i = 0;
	used_size_b = b->used_size;
	used_size_a = a->used_size;
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
	pull_stack(b);
	a->used_size++;
	b->used_size--;
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

// void	rotate(s_swap *rotate)
// {
// 	int	tmp;
// 	int	size;
// 	int i;
	
// 	size = rotate->size - 1;
// 	i = 0;
// 	while (i < size)
// 	{
// 		tmp = rotate->array[i];
// 		rotate->array[i] = rotate->array[i + 1];
// 		rotate->array[i + 1] = tmp;
// 		i++;
// 	}
// }

void	rotate(s_swap *stack)
{
	int	tmp;

	ft_putstr("ra\n");
	tmp = stack->array[0];
	pull_stack((s_stack *)stack);
	stack->array[stack->used_size - 1] = tmp;
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

int		min_value(int	*array, int size)
{
	int	i;
	int	s_index;

	i = 0;
	s_index = i;
	while (i < size)
	{
		if (array[s_index] > array[i])
			s_index = i;
		i++;
	}
	return (s_index);
}

int	ft_issorted(s_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->used_size - 1)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	ft_find_smallest_number(s_stack *a)
{
	int	s_index;

	s_index = min_value(a->array, a->used_size);
	while (s_index != 0)
	{
		if (s_index <= 2)
			rotate((s_swap *)a);
		else
			reverse_rotate((s_swap*)a);
		s_index = min_value(a->array, a->used_size);
	}
}



// void	sort_5(s_stack *a, s_stack *b)
// {	
// 	int	i;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		b->size +=0;
// 		// if (a->used_size == 5)
// 		// {
// 		// 	ft_find_smallest_number(a);
// 		// 	push_b(a, b);
// 		// 	i++;
// 		// }
// 		// if (a->used_size == 4)
// 		// {
// 		// 	ft_find_smallest_number(a);
// 		// 	push_b(a, b);
// 		// 	i++;
// 		// }
// 		// sort_3((s_swap *)a);
// 		// // while (i > 0)
// 		// // {
// 		// // 	push_a(a, b);
// 		// // 	i--;
// 		// // }
// 		ft_find_smallest_number(a);
// 		push_b(a, b);
// 		i++;
// 	}
// 		pull_stack(a);
// 		//a->used_size -= 1;
// 		//rotate((s_swap *)a);
// 		ft_find_smallest_number(a);
// 		pull_stack(a);
// 		push_b(a, b);
// }
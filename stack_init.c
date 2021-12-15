/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:02:03 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/15 01:44:02 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(s_swap *info, s_stack *stack_a, s_stack *stack_b)
{
	stack_a->array = info->array;
	stack_a->size = info->size;
	stack_a->used_size = info->size;
	stack_b->used_size = 0;
	stack_b->array = (int *)malloc(sizeof(int) * info->size);
	stack_b->size = info->size;
	info->used_size = stack_a->used_size;
}
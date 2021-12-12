/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:23:55 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/12 14:27:13 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    s_swap info;
	s_stack stack_a;
	s_stack stack_b;
    if (argc == 1)
        error_msg("Stack is empty");
	info.size = argc - 1;
    info.array = convert_args(info.size, argv);
	duplicate_nambers(&info);
	sorted_stack(&info);
	stack_a.array = info.array;
	stack_a.size = info.size;
	stack_a.used_size = info.size - 1;
	stack_b.used_size = 0;
	stack_b.array = (int*)malloc(sizeof(int) * info.size);
	stack_b.size= info.size;
	if (argc == 3)
		sort_2(&info);
	else if (argc == 4)
		sort_3(&info);
	else
		sort_5(&stack_a, &stack_b);
	/*********** testing *********/
	int i = -1;
	printf("----------------------\n");
	printf("A : |size = %d||used_size = %d|\n", stack_a.size, stack_a.used_size);
	printf("B : |size = %d||used_size = %d|\n", stack_b.size, stack_b.used_size);
	printf("--------stack A---------\n");
	while (++i <= stack_a.used_size)
		printf("%d\n", stack_a.array[i]);	
	printf("--------stack b---------\n");
	printf("%d\n", stack_b.array[0]);
	printf("%d\n", stack_b.array[1]);
	printf("%d\n", stack_b.array[2]);
	printf("%d\n", stack_b.array[4]);
	/********** end of tisting *******/
	return (0);
}

//parsing one argument that contain multi numbers
// sort stack that containe 5 element
// sort stack that containe 10 element
// sort stack that containe more than 10 element
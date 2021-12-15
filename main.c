/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:23:55 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/15 06:21:43 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    s_swap info;
	s_stack stack_a;
	s_stack stack_b;
    if (argc == 1)
        error_msg();
	info.size = argc - 1;
    info.array = convert_args(info.size, argv);
	duplicate_nambers(&info);
	sorted_stack(&info);
	stack_init(&info, &stack_a, &stack_b);
	if (argc == 3)
		sort_2(&stack_a);
	else if (argc == 4)
		sort_3(&stack_a);
	else if (argc == 6 || argc == 5)
		sort_5(&stack_a, &stack_b);
	else if (argc > 6  && argc <= 11)
		sort_10(&stack_a, &stack_b);
	// else if (stack_a.size > 10 && stack_a.size <= 100)
	// 	sort_100(&stack_a, &stack_b);
	else
		sort_500(&stack_a, &stack_b);
	/*********** testing *********/
	// int i = -1;
	// printf("----------------------\n");
	// printf("A : |size = %d||used_size = %d|\n", stack_a.size, stack_a.used_size);
	// printf("B : |size = %d||used_size = %d|\n", stack_b.size, stack_b.used_size);
	// printf("--------stack A---------\n");
	// while (++i < stack_a.size)
	// 	printf("%d\n", stack_a.array[i]);
	// printf("--------stack b---------\n");
	// printf("%d\n", stack_b.array[0]);
	// printf("%d\n", stack_b.array[1]);
	// printf("%d\n", stack_b.array[2]);
	// printf("%d\n", stack_b.array[3]);

	/********** end of testing *******/
	// free(info.array);
	// free(stack_b.array);
	/*********** leaks test **********/
	// while(1)
	// {
	// 	printf("1");
	// }
	/********** end of leak test *******/
	return (0);
}

//parsing one argument that contain multi numbers
// remove sorting 100 element algorithm
// finish the project
// norminette
// optimize code
// finish*******

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:23:55 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/11 08:39:30 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    s_swap info;

    if (argc == 1)
        error_msg("Stack is empty");
	info.size = argc - 1;
    info.array = convert_args(info.size, argv);
	duplicate_nambers(&info);
	sorted_stack(&info);
	if (argc == 2)
		sort_2()
	if (argc == 4)
		sort_3(&info);
	int i = -1;
	while (++i < info.size )
		printf("%d\n", info.array[i]);
	return (0);
}
// sorted stack problem
//parsing one argument that contain multi numbers
// sort stack that contiane 3 element
// sort stack that containe 5 element
// sort stack that containe 10 element
// sort stack that containe more than 10 element
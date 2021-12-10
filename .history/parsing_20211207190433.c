/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:47:16 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/07 19:04:33 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    *convert_args(int argc, char **argv)
{
    int     count;
    int     *array;

    count = 0;
    array = (int *)malloc(sizeof(int) * argc);
	while (argv[count++])
    {
        array[count] = ft_atoi(argv[count]);
        if (array[count] > INT_MAX && array[count] < INT_MIN)
			count++;
		else
		{
			free(array);
			exit(1);
		}
		
    }
    count = 0;
    while (argc > 0)
	{
		if (array[count] == array[count + 1])
		{
			free(array);
			exit(1);
		}
		count++;
	}
	return (array);
}
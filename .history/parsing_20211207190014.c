/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:47:16 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/07 19:00:14 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    *convert_args(int argc, char **argv)
{
    int     count;
    int     *array;

    count = 0;
    array = ()
	while (argv[count++])
    {
        array[count] = ft_atoi(argv[count]);
        if (array[count] > INT_MAX || array[count] < INT_MIN)
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
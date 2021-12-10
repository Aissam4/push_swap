/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:47:16 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/07 16:56:57 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     int_convert(char *argv)
{
    int     num;
    
    num = ft_atoi(argv);
    if (num > INT_MAX || num < INT_MIN)
        return (0);
    return (num);
}
void    convert_args(int argc, char **argv)
{
    int     argv_count;
    int     array[argc];

    argv_count = 0;
    while (argv[argv_count])
    {
        array[argv_count] = int_convert(argv[argv_count]);
        
    }
}
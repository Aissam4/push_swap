/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:23:50 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/11 08:39:47 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_swap 
{
    int *array;
	int	size;
}   s_swap;

typedef struct t_stack_a
{
    int *array;
	int	size;
}   stack_a;

/********* LIBFT **********/
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
void	ft_putstr(char *s);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
long long int	ft_atoi(const char *str);
/********* ERRORS **********/
void    error_msg(char *s);
/********* PARSING *********/
void	sorted_stack(s_swap *stack);
int		check_duplicated(int size, int *array, int number);
void	duplicate_nambers(s_swap *stack);
int    *convert_args(int argc, char **argv);
/********* SORTING **********/
void		sort_2(s_swap *sorting)
void	sort_3(s_swap *sorting);
void	swap(s_swap *swap);
void	rotate(s_swap *rotate);
void	reverse_rotate(s_swap *reverse_rotate);
int		min_value(int	*array, int size);

#endif
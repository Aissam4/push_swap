/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:23:50 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/17 15:24:40 by abarchil         ###   ########.fr       */
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
	int	used_size;
}   s_swap;

typedef struct t_stack
{
    int *array;
	int	size;
	int	used_size;
}   s_stack;

/********* LIBFT **********/
size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
void			ft_putstr(char *s);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
long long int	ft_atoi(const char *str);
/********* ERRORS **********/
void    error_msg(void);
/******* INIT STACK *******/
char	**stacks_init(char *string, s_stack *a, s_stack *b);
/********* PARSING *********/
int		ft_isnumber(char *number);
char	*argv_to_string(char **av);
int		ft_issorted(s_stack *stack);
int		ft_count_numbers(char *string);
void	duplicate_nambers(s_stack *stack);
int		check_duplicated(int size, int *array, int number);
/********* SORTING **********/

void	sort_2(s_stack *stack);
void	sort_3(s_stack *stack);
int		*simple_sort(s_stack *stack);
void	sort_10(s_stack *a, s_stack *b);
void	sort_100(s_stack *a, s_stack *b);
void	sort_500(s_stack *a, s_stack *b);
void	sort_5(s_stack *stack, s_stack *b);
void	sort_remainder(s_stack *a, s_stack *b);
void	sort_remainder_2(s_stack *a, s_stack *b);

/******** SORTING UTILS *****/

void	rotate_b(s_stack *b);
void	swap(s_stack *stack);
void	rotate_a(s_stack *stack);
void	swap_ptr(int *a, int *b);
int		min_value(s_stack *stack);
int		max_value(s_stack *stack);
void	reverse_rotate_b(s_stack *b);
void	find_max_value(s_stack *stack);
void	reverse_rotate_a(s_stack *stack);
void	find_smallest_number(s_stack *stack, int i);
void	find_index_push(s_stack *a, s_stack *b, int key);

/********* PUSH & POP *******/

void	push_b(s_stack *a, s_stack *b);
void	push_a(s_stack *a, s_stack *b);
void	push_stack(s_stack *stack);
void	pop_stack(s_stack *stack);

#endif
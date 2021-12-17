/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:23:50 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/18 00:00:06 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_swap
{
	int		*array;
	int		size;
	int		used_size;
}	t_swap;

typedef struct s_stack
{
	int		*array;
	int		size;
	int		used_size;
}	t_stack;

long long int	ft_atoi(const char *str);
void			ft_putstr(char *s);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			ft_store_numbers(char *string, t_stack *a, t_stack *b);
void			error_msg(void);
void			duplicate_nambers(t_stack *stack);
void			sort_2(t_stack *stack);
void			sort_3(t_stack *stack);
void			sort_10(t_stack *a, t_stack *b);
void			sort_100(t_stack *a, t_stack *b);
void			sort_500(t_stack *a, t_stack *b);
void			sort_5(t_stack *stack, t_stack *b);
void			sort_remainder(t_stack *a, t_stack *b);
void			sort_remainder_2(t_stack *a, t_stack *b);
void			*ft_memset(void *s, int c, size_t n);
void			rotate_b(t_stack *b, int print);
void			ft_bzero(void *s, size_t n);
void			swap(t_stack *stack, int print);
void			rotate_a(t_stack *stack, int print);
void			swap_ptr(int *a, int *b);
void			reverse_rotate_b(t_stack *b, int print);
void			find_max_value(t_stack *stack);
void			reverse_rotate_a(t_stack *stack, int print);
void			find_smallest_number(t_stack *stack, int i);
void			find_index_push(t_stack *a, t_stack *b, int key);
void			pop_stack(t_stack *stack);
void			push_stack(t_stack *stack);
void			push_a(t_stack *a, t_stack *b, int print);
void			push_b(t_stack *a, t_stack *b, int print);
void			push_to_top(t_stack *stack, int index);
char			**stacks_init(char *string, t_stack *a, t_stack *b);
char			*argv_to_string(char **av);
char			*get_next_line(int fd);
char			**ft_split(char const *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_isdigit(int c);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_isnumber(char *number);
int				ft_issorted(t_stack *stack);
int				ft_count_numbers(char *string);
int				check_duplicated(int size, int *array, int number);
int				*simple_sort(t_stack *stack);
int				min_value(t_stack *stack);
int				max_value(t_stack *stack);
size_t			ft_strlen(const char *s);

#endif

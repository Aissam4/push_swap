/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:23:50 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/07 18:55:30 by abarchil         ###   ########.fr       */
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
    
}   s_swap;
/********* LIBFT **********/
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int	ft_atoi(const char *str);
/********* ERRORS **********/
void    error_msg(void);
/********* PARSING *********/
int    *convert_args(int argc, char **argv)
#endif
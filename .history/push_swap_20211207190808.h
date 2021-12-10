/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 11:23:50 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/07 19:08:08 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct drawing_win_floor_wall // norme name
{
    int     posx;
    int     posy;
    int     collectible_count;
    char    **map;
    void    *mlx;
    void    *mlx_window;
    void    *floor;
    void    *wall;
    void    *collectible;
    void    *Player;
    void    *end_point;
    void    *sprite_1;
    void    *sprite_2;
    void    *sprite_3;
    int     w;
    int     h;
    int     animate;
}   drawing_map;
typedef struct t_swap 
{
    int *array;

}   s_swap;
/********* LIBFT **********/
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int	ft_atoi(const char *str);
/********* ERRORS **********/
void    error_msg(void);
/********* PARSING *********/
int    *convert_args(int argc, char **argv);
#endif
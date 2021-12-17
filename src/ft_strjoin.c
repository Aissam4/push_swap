/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:31:36 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/17 02:28:28 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result_tab;
	unsigned int	total_len;
	unsigned int	s1_count;
	unsigned int	s2_count;

	s1_count = 0;
	s2_count = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	result_tab = (char *)malloc(sizeof(char) * total_len + 1);
	if (!result_tab)
		return (NULL);
	while (s1[s1_count])
	{
		result_tab[s1_count] = s1[s1_count];
		s1_count++;
	}
	while (s2[s2_count])
	{
		result_tab[s1_count] = s2[s2_count];
		s1_count++;
		s2_count++;
	}
	result_tab[s1_count] = '\0';
	free((char *)s1);
	return (result_tab);
}

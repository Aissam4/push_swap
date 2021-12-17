/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 14:55:52 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/17 02:25:06 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_memzero(size_t size)
{
	char	*dest;
	int		count;

	count = 0;
	dest = (char *)malloc(sizeof(char) * size);
	if (dest)
	{
		while (size != 0)
		{
			dest[count++] = 0;
			size--;
		}
		return (dest);
	}
	else
		return (NULL);
}

int	word_length(char const *s, char c)
{
	int	len;

	len = 0;
	if (*s != c && *s != 0)
	{
		len++;
		s++;
	}
	while (*s != 0)
	{
		if (*s != c)
			len++;
		s++;
	}
	return (len + 1);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count;
	unsigned int	j;
	char			**splited;

	if (s == NULL)
		return (NULL);
	splited = (char **)malloc(sizeof(char *) * word_length(s, c));
	if (!splited)
		return (NULL);
	j = 0;
	while (*s != 0)
	{
		count = 0;
		while (s[count] != c && s[count] != 0)
			count++;
		if (count)
		{
			splited[j++] = ft_memcpy(ft_memzero(count + 1), s, count);
			s = &s[count];
		}
		else
			s++;
	}
	splited[j] = NULL;
	return (splited);
}

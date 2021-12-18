/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 05:02:29 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/18 01:08:12 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strdup(char *str)
{
	int		count;
	char	*res;

	count = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (count + 1));
	if (!res)
		return (NULL);
	ft_memmove(res, str, count);
	res[count] = 0;
	return (res);
}

char	*get_next_line(int fd)
{
	int		byte;
	int		i;
	char	line[1000000];
	char	buffer[1];

	ft_bzero(line, 1000000);
	i = 0;
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, buffer, 1);
		line[i++] = buffer[0];
		if (buffer[0] == '\n')
			return (ft_strdup(line));
	}
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}

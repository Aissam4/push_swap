/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:29:03 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/11 15:01:15 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ""

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest1;
	char	*src1;
	size_t	count;

	dest1 = (char *)dest;
	src1 = (char *)src;
	count = 0;
	if (!dest && !src)
		return (NULL);
	if (dest1 < src1)
	{
		while (count < n)
		{
			dest1[count] = src1[count];
			count++;
		}
	}
	else
	{
		while (n-- > 0)
			dest1[n] = src1[n];
	}
	return (dest1);
}

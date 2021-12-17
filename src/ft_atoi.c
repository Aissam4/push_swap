/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarchil <abarchil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:17:45 by abarchil          #+#    #+#             */
/*   Updated: 2021/12/17 03:34:26 by abarchil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long long int	ft_atoi(const char *str)
{
	int	i;
	int	signe;
	long long int	result;

	i = 0;
	result = 0;
	signe = 1;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			signe = -1;
	if (!(str[i] >= '0' && str[i] <= '9'))
		error_msg();
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ' && str[i])
		error_msg();
	return (result * signe);
}
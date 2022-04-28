/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:15:56 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/13 13:16:12 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	check(long long result, short sign)
{
	if (result > 2147483648 || result < -2147483649)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return ((int)result * (int)sign);
}

int	ft_atoi(const char *theString)
{
	int			sign;
	int			i;
	int			j;
	long long	result;

	j = 0;
	i = 0;
	result = 0;
	sign = 1;
	while ((theString[i] >= 9 && theString[i] <= 13) || theString[i] == 32)
		i++;
	if (theString[i] == '-' || theString[i] == '+')
	{
		if (theString[i] == '-')
			sign = sign - 2;
		i++;
	}
	while (theString[i] >= '0' && theString[i] <= '9')
	{
		result = (result * 10) + theString[i] - '0';
		i++;
	}
	return (check(result, sign));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:30:52 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/22 18:42:41 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../push_swap.h"

int	check(long long result, int sign)
{
	if (result > 2147483647 || result < -2147483648)
	{
		exit_error();
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
/*
int	main(void)
{
	char	*str;

	str = "  	    -2147483649a9812";
	printf("FT_ATOI :\n%d  ||  ", ft_atoi(str));
	printf("%d\n\n------------------------------------", atoi(str));
}
*/

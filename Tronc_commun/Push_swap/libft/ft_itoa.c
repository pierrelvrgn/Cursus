/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:05:27 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/11 10:10:44 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_char(long long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			i;
	int			j;
	long long	nb;

	nb = (long long)n;
	i = count_char(nb);
	j = count_char(nb);
	result = malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	if (nb < 0)
	{
		result[0] = '-';
		nb = nb * -1;
	}
	while (nb > 9)
	{
		result[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (nb <= 9 && nb >= 0)
		result[i--] = nb + '0';
	result[j + 1] = '\0';
	return (result);
}

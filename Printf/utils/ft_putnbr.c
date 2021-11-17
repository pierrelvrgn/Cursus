/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:40:04 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/17 13:44:54 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(unsigned long long nb)
{
	int	size;

	size = 0;
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = nb *(-1);
		size++;
	}
	if (nb >= 0 && nb <= 9)
		size += ft_putchar(nb);
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (size);
}

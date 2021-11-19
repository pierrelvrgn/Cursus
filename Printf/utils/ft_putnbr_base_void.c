/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_void.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 15:08:57 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/19 15:15:58 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_base_void(unsigned long int nb, char *base)
{
	int	size;

	size = 0;
	if (nb >= 0 && nb < 16)
		size += ft_putchar(base[nb]);
	if (nb >= 16)
	{
		size += ft_putnbr_base_void(nb / 16, base);
		size += ft_putchar(base[nb % 16]);
	}
	return (size);
}

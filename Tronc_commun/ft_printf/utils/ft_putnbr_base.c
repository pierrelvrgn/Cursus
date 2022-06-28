/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:28:41 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/19 14:43:27 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_base(unsigned int nb, char *base)
{
	int	size;

	size = 0;
	if (nb >= 0 && nb < 16)
		size += ft_putchar(base[nb]);
	if (nb >= 16)
	{
		size += ft_putnbr_base(nb / 16, base);
		size += ft_putchar(base[nb % 16]);
	}
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:28:30 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/19 14:30:44 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb >= 0 && nb <= 9)
		size += ft_putchar((unsigned char)(nb + '0'));
	if (nb >= 10)
	{
		size += ft_putnbr_unsigned(nb / 10);
		size += ft_putnbr_unsigned(nb % 10);
	}
	return (size);
}

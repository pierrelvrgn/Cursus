/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:59:17 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/19 15:15:22 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_void_hexa(void *nb)
{
	int	size;

	size = 0;
	size += ft_putstr("0x");
	size += ft_putnbr_base_void((unsigned long int)nb, "0123456789abcdef");
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_small_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:39:26 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/19 14:40:56 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_small_hexa(unsigned int nb)
{
	int	size;

	size = 0;
	size += ft_putnbr_base(nb, "0123456789abcdef");
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_big_hexa.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 14:41:26 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/19 14:41:27 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_big_hexa(unsigned int nb)
{
	int	size;

	size = 0;
	size += ft_putnbr_base(nb, "0123456789ABCDEF");
	return (size);
}

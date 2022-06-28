/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:28:36 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/19 15:13:04 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printer(va_list	args, char s)
{
	int	size;

	size = 0;
	if (s == 'd' || s == 'i')
		size += ft_putnbr((int)va_arg(args, int));
	else if (s == 'c')
		size += ft_print_char((int)va_arg(args, int));
	else if (s == 's')
		size += ft_putstr((char *)va_arg(args, char *));
	else if (s == 'u')
		size += ft_putnbr_unsigned((unsigned int)va_arg(args, unsigned int));
	else if (s == 'x')
		size += ft_print_small_hexa((unsigned int)va_arg(args, unsigned int));
	else if (s == 'X')
		size += ft_print_big_hexa((unsigned int)va_arg(args, unsigned int));
	else if (s == 'p')
		size += ft_print_void_hexa((void *)va_arg(args, void *));
	else
		return (0);
	return (size);
}

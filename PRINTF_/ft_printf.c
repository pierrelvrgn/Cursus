/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:22:39 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/19 15:13:26 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		size;
	int		result;
	int		i;
	va_list	args;

	i = 0;
	size = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			result = ft_printer(args, str[i + 1]);
			if (result == 0 && str[i + 1] != 's')
				size += ft_putchar(str[i + 1]);
			i++;
			size += result;
		}
		else
			size += ft_putchar(str[i]);
		i++;
	}
	return (size);
}
/*
int	main(void)
{
	int	size;

	size = 0;
	size += ft_printf("Bien %p evide;emt", 123456);
	printf("\n%d", size);
	return (0);
}
*/

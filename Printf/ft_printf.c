/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:15:03 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/18 12:48:57 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printer(va_list	args, int nb)
{
	int	printer[10];
	int	size;

	size = 0;
	printer[0] = ft_print_c(args);
	printer[1] = ft_print_s(args);
//	printer[2] = ft_print_p(args);
	printer[3] = ft_print_d(args);
	printer[4] = ft_print_i(args);
//	printer[5] = ft_print_u(args);
//	printer[6] = ft_print_x(args);
//	printer[7] = ft_print_maj_x(args);
//	printer[8] = ft_print_percent(args);
	size = printer[nb];
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			size;
	int			i;
	char		*s;
	int			nb;

	s = "cspdiuxX%";
	i = 0;
	nb = 0;
	size = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			while (s[nb])
			{
				if (s[nb] == str[i +1])
				{
					size += ft_printer(args, nb);
					i++;
				}
				nb++;
			}
			nb = 0;
		}
		putchar(str[i]);
		size++;
		i++;
	}
	va_end(args);
	return (size);
}
/*
int	main(void)
{
	printf("%u", printf("%s", "bien le bonjour\n"));
	printf("%u", ft_printf("%s", "bien le bonjour"));
}
*/

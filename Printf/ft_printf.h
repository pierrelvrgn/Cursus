/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 11:22:24 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/19 15:09:46 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_printer(va_list	args, char s);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr(int nb);
int	ft_print_char(int c);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_putnbr_base(unsigned int nb, char *base);
int	ft_print_small_hexa(unsigned int nb);
int	ft_print_big_hexa(unsigned int nb);
int	ft_print_void_hexa(void *nb);
int	ft_putnbr_base_void(unsigned long int nb, char *base);

#endif

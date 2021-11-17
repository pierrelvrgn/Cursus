/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 11:15:34 by plavergn          #+#    #+#             */
/*   Updated: 2021/11/17 13:54:08 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_putstr(char *str);
int	ft_putchar(int c);
int	ft_putnbr(unsigned long long n);
int	ft_printf(const char *str, ...);
int	ft_strncmp(const char *first, const char *second, size_t length);
int	ft_print_c(char c);
int	ft_print_d(int d);
int	ft_print_i(int i);
int	ft_print_s(char	*s);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:15:13 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/11 12:44:58 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_putchar(int c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n >= 0 && n <= 9)
		ft_putchar((n + '0'));
}

void	ft_putstr(char *str, unsigned int a, unsigned int b, t_philo *philo)
{
	int	i;

	ft_putnbr(a);
	write(1, " ", 1);
	ft_putnbr(b);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

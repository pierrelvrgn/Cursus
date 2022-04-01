/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:40:08 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/24 13:14:13 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_server.h"

int	g_index = 0;

void	ft_putchar(int nb)
{
	nb += '0';
	write (1, &nb, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write (1, "-", 1);
		ft_putnbr(nb *(-1));
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb);
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	handler(int byte)
{
	int		i;
	int		result;
	int		j;
	int		temp[8];

	j = 128;
	result = 0;
	if (byte == 30)
		byte = 0;
	else if (byte == 31)
		byte = 1;
	temp[g_index] = byte;
	g_index++;
	if (g_index == 8)
	{
		i = 0;
		while (i < 8)
		{
			result += (temp[i] * j);
			j = j / 2;
			i++;
		}
		write(1, &result, 1);
		g_index = 0;
	}
}

int	main(void)
{
	int			i;
	static int	nb;
	int			pid;

	i = 0;
	nb = 0;
	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	exit(EXIT_SUCCESS);
	return (0);
}

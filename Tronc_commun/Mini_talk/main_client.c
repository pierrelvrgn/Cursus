/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:45:57 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/24 13:21:38 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_client.h"

static int	check(long long result, short sign)
{
	if (result > 2147483648 || result < -2147483649)
	{
		if (sign == 1)
			return (-1);
		return (0);
	}
	return ((int)result * (int)sign);
}

static int	ft_atoi(const char *theString)
{
	int			sign;
	int			i;
	int			j;
	long long	result;

	j = 0;
	i = 0;
	result = 0;
	sign = 1;
	while ((theString[i] >= 9 && theString[i] <= 13) || theString[i] == 32)
		i++;
	if (theString[i] == '-' || theString[i] == '+')
	{
		if (theString[i] == '-')
			sign = sign - 2;
		i++;
	}
	while (theString[i] >= '0' && theString[i] <= '9')
	{
		result = (result * 10) + theString[i] - '0';
		i++;
	}
	return (check(result, sign));
}

void	set_tab(t_var *vars, char argv)
{
	vars->c = (unsigned char)argv;
	vars->k = 0;
	while (vars->k < 8)
	{
		vars->tab[vars->k] = 0;
		vars->k++;
	}
	vars->k = 0;
	while (vars->c > 0)
	{
		if (vars->c % 2 == 0)
			vars->tab[vars->k] = 0;
		else if (vars->c % 2 != 0)
			vars->tab[vars->k] = 1;
		vars->c = vars->c / 2;
		vars->k++;
	}
	while (vars->k < 8)
	{
		vars->tab[vars->k] = 0;
		vars->k++;
	}
}

void	convert(char *argv, int pid, t_var *vars)
{
	vars->i = 0;
	while (argv[vars->i])
	{
		set_tab(vars, argv[vars->i]);
		vars->k = 7;
		while (0 <= vars->k)
		{
			if (vars->tab[vars->k] == 0)
				kill(pid, SIGUSR1);
			else if (vars->tab[vars->k] == 1)
				kill(pid, SIGUSR2);
			usleep(100);
			vars->k--;
		}
		vars->i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	t_var	*vars;

	vars = malloc(sizeof(t_var));
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	convert(argv[2], pid, vars);
	free(vars);
	return (0);
}

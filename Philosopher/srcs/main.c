/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:34:17 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/14 10:03:26 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] >= 48 && argv[i] <= 57)
			i++;
		else
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 5 || argc == 6)
	{
		while (argv[i])
		{
			if (ft_isdigit(argv[i]))
				return (1);
			i++;
		}
		if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
			|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0
			|| (argc == 6 && ft_atoi(argv[5]) <= 0))
			return (1);
		if (ft_atoi(argv[1]) > 2147483647 || ft_atoi(argv[2]) > 2147483647
			|| ft_atoi(argv[3]) > 2147483647 || ft_atoi(argv[4]) > 2147483647
			|| (argc == 6 && ft_atoi(argv[5]) > 2147483647))
			return (1);
		if (init_all(argv, argc))
			return (1);
	}
	else
		return (1);
	return (0);
}

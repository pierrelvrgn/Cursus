/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:01:56 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/27 09:43:14 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			**philo;
	struct timeval	start;
	size_t			i;

	i = 1;
	if (argc > 7)
		return (0);
	philo = malloc(sizeof(t_philo *) * (ft_atoi(argv[1]) + 1));
	philo[0] = malloc(sizeof(t_philo));
	philo[0]->info = malloc(sizeof(t_info));
	philo[0]->info->nb_philo = (size_t)ft_atoi(argv[1]);
	philo[0]->info->time_to_die = (size_t)ft_atoi(argv[2]);
	philo[0]->info->time_to_eat = (size_t)ft_atoi(argv[3]);
	philo[0]->info->time_to_sleep = (size_t)ft_atoi(argv[4]);
	gettimeofday(&start, NULL);
	philo[0]->time = start.tv_usec;
	while (i <= philo[0]->info->nb_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		init_philo_pair(philo, i);
		i++;
	}
	return (0);
}

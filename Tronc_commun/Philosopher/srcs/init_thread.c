/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:39:03 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/13 13:15:37 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	start_thread(t_philo *philo)
{
	pthread_create(philo->thread, NULL, use_thread, philo);
	pthread_detach(*philo->thread);
	pthread_join(*philo->thread, NULL);
}

void	*use_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->info->nb_philo == 1)
	{
		printf("%lu %lu has taken a fork\n", (ft_get_time()
				- philo->info->start), philo->index);
		ft_ms_sleep(philo->info->time_to_die, philo);
	}
	else
	{
		ft_think(philo);
		if (philo->index % 2 == 0)
			usleep(philo->info->time_to_eat * 0.9 * 1000);
		while (1)
		{
			ft_eat(philo);
			ft_sleep(philo);
			ft_think(philo);
		}
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:09:04 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/27 09:45:36 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_alive(t_philo *philo)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	if (philo->each_eat > 0 && (philo->last_eat - end.tv_usec)
		> philo->info->time_to_die)
		return (0);
	else if (philo->each_eat == 0 && (philo->time - end.tv_usec)
		> philo->info->time_to_die)
		return (0);
	else
		return (1);
	return (0);
}

void	*use_thread_pair(void *arg)
{
	t_philo	**philo;
	int		i;
	int		index;

	i = 1;
	philo = (t_philo **)arg;
	index = philo[0]->index;
//	philo[index]->index = index;
	printf("%d\n", index);
	if ((index % 2) == 1)
	{
		while (is_alive(philo[index]) == 1)
		{
			printf("i\n");
			ft_eat(philo);
			ft_sleep(philo);
			ft_think(philo);
		}
		exit(EXIT_FAILURE);
	}
	else if ((index % 2) == 0)
	{
		ft_think(philo);
		while (is_alive(philo[index]) == 1)
		{
			printf("a\n");
			ft_eat(philo);
			ft_sleep(philo);
		}
		exit(EXIT_FAILURE);
	}
	return (NULL);
}

void	init_philo_pair(t_philo **philo, int index)
{
	philo[index]->info = malloc(sizeof(t_info));
	philo[index]->info->nb_philo = philo[0]->info->nb_philo;
	philo[index]->info->time_to_die = philo[0]->info->time_to_die;
	philo[index]->info->time_to_eat = philo[0]->info->time_to_eat;
	philo[index]->info->time_to_sleep = philo[0]->info->time_to_sleep;
	philo[0]->index = index;
	philo[index]->time = philo[0]->time;
	philo[index]->each_eat = 0;
	philo[index]->thread = malloc(sizeof(pthread_t));
	philo[index]->fork = malloc(sizeof(pthread_mutex_t));
	pthread_create(philo[index]->thread, NULL, use_thread_pair, philo);
	pthread_detach(*philo[index]->thread);
	pthread_join(*philo[index]->thread, NULL);
}
/*
void	*use_thread_odd(void *arg)
{
	t_philo	**philo;
	int		i;

	i = 1;
	philo = (t_philo **)arg;
	if (philo[0]->info->nb_philo % 2 == 0)
	{
		while(i < philo[0]->info->nb_philo)
		{
			philo->[i]
			i++;
		}
	}
	while (1)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
*/
/*
void	init_philo_odd(t_philo **philo, int index)
{
	philo[index]->info->nb_philo = philo[0]->info->nb_philo;
	philo[index]->info->time_to_die = philo[0]->info->time_to_die;
	philo[index]->info->time_to_eat = philo[0]->info->time_to_eat;
	philo[index]->info->time_to_sleep = philo[0]->info->time_to_sleep;
	philo[index]->index = index;
	philo[index]->time = philo[0]->time;
	pthread_create(philo[index]->thread, NULL, use_thread_pair, philo[index]);
	pthread_join(*philo[index]->thread, NULL);
}
*/

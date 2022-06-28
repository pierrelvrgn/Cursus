/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:39:15 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/14 08:56:18 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	ft_norm_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_right);
	philo->fork_bool_right = 0;
	pthread_mutex_lock(philo->ft_print);
	printf("%lu %lu has taken a fork\n",
		(ft_get_time() - philo->info->start), philo->index);
	printf("%lu %lu has taken a fork\n",
		(ft_get_time() - philo->info->start), philo->index);
	pthread_mutex_unlock(philo->ft_print);
	pthread_mutex_lock(philo->ft_print);
	printf("%lu %lu is eating\n",
		(ft_get_time() - philo->info->start), philo->index);
	philo->last_eat = ft_get_time();
	pthread_mutex_unlock(philo->ft_print);
	ft_ms_sleep(philo->info->time_to_eat, philo);
	pthread_mutex_unlock(philo->fork_right);
	pthread_mutex_unlock(philo->fork_left);
	philo->fork_bool_right = 1;
	philo->fork_bool_left = 1;
	philo->eat = 1;
	philo->each_eat++;
	philo->sleep = 0;
}

void	ft_eat(t_philo *philo)
{
	if (philo->eat == 0 && philo->sleep == 1)
	{
		if (philo->fork_bool_left == 0)
			return ;
		pthread_mutex_lock(philo->fork_left);
		philo->fork_bool_left = 0;
		if (philo->fork_bool_right == 0)
		{
			philo->fork_bool_left = 1;
			pthread_mutex_unlock(philo->fork_left);
			return ;
		}
		ft_norm_eat(philo);
	}
}

void	ft_sleep(t_philo *philo)
{
	if (philo->eat == 1 && philo->sleep == 0)
	{
		philo->eat = 0;
		philo->sleep = 1;
		philo->think = 0;
		pthread_mutex_lock(philo->ft_print);
		printf("%lu %lu is sleeping\n",
			(ft_get_time() - philo->info->start), philo->index);
		pthread_mutex_unlock(philo->ft_print);
		ft_ms_sleep(philo->info->time_to_sleep, philo);
	}
}

void	ft_think(t_philo *philo)
{
	if (philo->think == 0)
	{
		philo->think = 1;
		pthread_mutex_lock(philo->ft_print);
		printf("%lu %lu is thinking\n",
			(ft_get_time() - philo->info->start), philo->index);
		pthread_mutex_unlock(philo->ft_print);
	}
}

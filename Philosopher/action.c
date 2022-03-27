/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:08:36 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/27 09:33:28 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_eat(t_philo **philo)
{
	struct timeval	end;
	struct timeval	start;
	int				index;

	index = philo[0]->index;
	gettimeofday(&start, NULL);
	pthread_mutex_lock(philo[index]->fork);
	pthread_mutex_lock(philo[index++]->fork);

//	if (!philo[index]->fork && philo[index]->fork)
//	{
//		philo[index]->eat = 0;
//		pthread_mutex_unlock(philo[index]->fork);
//		return (NULL);
//	}
//	if (!philo[index]->fork && philo[index]->fork)
//	{
//		philo[index]->eat = 0;
//		pthread_mutex_unlock(philo[index]->fork);
//		return (NULL);
//	}
	printf("%lu : %d My_turn_eat\n", (philo[index]->time - start.tv_usec),
		philo[index]->index);
	usleep(philo[index]->info->time_to_eat);
	pthread_mutex_unlock(philo[index]->fork);
	pthread_mutex_unlock(philo[index++]->fork);
	philo[index]->eat = 1;
	printf("\n");
	gettimeofday(&end, NULL);
	philo[index]->last_eat = end.tv_usec;
	philo[index]->each_eat++;
	return (NULL);
}

void	*ft_sleep(t_philo **philo)
{
	struct timeval	end;
	int				index;

	index = philo[0]->index;
	gettimeofday(&end, NULL);
	printf("%lu	: %d Sleep\n", (philo[index]->time - end.tv_usec),
		philo[index]->index);
	usleep(philo[index]->info->time_to_sleep);
	philo[index]->sleep = 1;
	return (NULL);
}

void	*ft_think(t_philo **philo)
{
	struct timeval	end;
	int				index;

	index = philo[0]->index;
	gettimeofday(&end, NULL);
	printf("%lu	: %d think\n", (philo[index]->time - end.tv_usec),
		philo[index]->index);
	usleep((philo[index]->info->time_to_eat - 10));
	return (NULL);
}

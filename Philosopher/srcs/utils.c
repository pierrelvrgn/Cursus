/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:38:22 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/14 09:12:45 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

size_t	ft_get_time(void)
{
	struct timeval	start;
	size_t			result;

	gettimeofday(&start, NULL);
	result = ((start.tv_sec * 1000) + (start.tv_usec / 1000));
	return (result);
}

void	ft_ms_sleep(size_t time, t_philo *philo)
{
	size_t	i;

	i = ft_get_time();
	usleep(time * 0.95 * 1000);
	if (philo->info->nb_philo > 100)
	{
		while (i > (ft_get_time() - time))
			usleep(500);
	}
	while (i > (ft_get_time() - time))
		usleep(100);
}

int	all_alive(t_philo *philo, t_info *info)
{
	if (philo->last_eat < (size_t)(ft_get_time - info->time_to_die))
		return (0);
	return (1);
}

int	is_alive_2(t_philo **philo, t_info *info)
{
	size_t	index;
	size_t	eat;

	index = 0;
	eat = 0;
	while (index < info->nb_philo)
	{
		if (philo[index]->each_eat == info->max_eat)
			eat++;
		if ((ft_get_time() - philo[index]->last_eat)
			>= info->time_to_die)
		{
			pthread_mutex_lock(info->ft_print);
			printf("%lu %lu died\n", (ft_get_time()
					- info->start), index + 1);
			return (0);
		}
		index++;
	}
	if (info->nb_philo > 1 && eat == (info->nb_philo - 1))
	{
		pthread_mutex_lock(info->ft_print);
		return (0);
	}
	return (1);
}

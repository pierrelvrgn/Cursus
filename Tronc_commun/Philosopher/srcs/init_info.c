/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:39:10 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/13 13:19:15 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	init_variable(t_info *info, char **argv, int argc)
{
	info->dead = 1;
	info->nb_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->max_eat = -1;
	info->start = ft_get_time();
	info->ft_print = malloc(sizeof(pthread_mutex_t));
	if (!info->ft_print)
	{
		free(info);
		return (1);
	}
	pthread_mutex_init(info->ft_print, NULL);
	if (argc == 6)
		info->max_eat = ft_atoi(argv[5]);
	return (0);
}

int	init_info(t_info *info, char **argv, int argc)
{
	if (init_variable(info, argv, argc))
		return (1);
	info->fork = malloc(sizeof(pthread_mutex_t *) * info->nb_philo);
	info->fork_bool = malloc(sizeof(size_t *) * info->nb_philo);
	if (!info->fork)
	{
		free(info->ft_print);
		free(info);
		return (1);
	}
	if (init_fork(info))
		return (1);
	return (0);
}

int	init_fork(t_info *info)
{
	int	index;

	index = 0;
	while (index < info->nb_philo)
	{
		info->fork_bool[index] = 1;
		info->fork[index] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(info->fork[index], NULL);
		if (!info->fork[index])
		{
			free(info->fork);
			free(info);
			return (1);
		}
		index++;
	}
	return (0);
}

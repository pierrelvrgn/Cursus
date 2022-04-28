/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:39:07 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/13 13:19:35 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_philo(t_philo **philo, t_info *info)
{
	int	index;

	index = 0;
	if (!philo)
	{
		free(info->fork);
		free(info);
		return (1);
	}
	while (index < info->nb_philo)
	{
		philo[index] = malloc(sizeof(t_philo));
		if (!philo[index])
		{
			ft_free(index, info, philo);
			return (1);
		}
		index++;
	}
	return (0);
}

static void	init_variable(t_philo *philo, t_info *info, int index)
{
	philo->each_eat = 0;
	philo->eat = 0;
	philo->sleep = 1;
	philo->think = 0;
	philo->ft_print = info->ft_print;
	philo->index = index + 1;
	philo->info = info;
	philo->last_eat = info->start;
	philo->thread = malloc(sizeof(pthread_t));
	philo->fork_right = info->fork[index];
	philo->fork_bool_right = info->fork_bool[index];
}

int	init_philo_variable(t_philo **philo, t_info *info)
{
	int	index;

	index = 0;
	while (index < info->nb_philo)
	{
		init_variable(philo[index], info, index);
		if (index == (info->nb_philo - 1))
		{
			philo[index]->fork_left = info->fork[0];
			philo[index]->fork_bool_left = info->fork_bool[0];
		}
		else
		{
			philo[index]->fork_left = info->fork[index + 1];
			philo[index]->fork_bool_left = info->fork_bool[index + 1];
		}
		index++;
	}
	return (0);
}

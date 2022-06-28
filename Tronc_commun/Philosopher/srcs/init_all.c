/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:42:16 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/13 13:13:07 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	free_all(t_philo **philo, t_info *info)
{
	size_t	index;

	index = 0;
	while (index < info->nb_philo)
	{
		free(philo[index]->thread);
		free(philo[index]);
		pthread_mutex_destroy(info->fork[index]);
		free(info->fork[index]);
		index++;
	}
	free(info->fork_bool);
	pthread_mutex_destroy(info->ft_print);
	free(info->ft_print);
	free(info->fork);
	free(info);
	free(philo);
}

int	init_all(char **argv, int argc)
{
	t_philo	**philo;
	t_info	*info;
	int		index;

	index = 0;
	info = malloc(sizeof(t_info));
	philo = malloc(sizeof(t_philo *) * (ft_atoi(argv[1])));
	if (init_info(info, argv, argc))
		return (1);
	if (init_philo(philo, info))
		return (1);
	if (init_philo_variable(philo, info))
		return (1);
	while (index < info->nb_philo)
	{
		start_thread(philo[index]);
		index++;
	}
	while (is_alive_2(philo, info))
		;
	free_all(philo, info);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:24:05 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/12 08:57:46 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_free(int philo_tab, t_info *info, t_philo **philo)
{
	int	index;

	index = 0;
	free(info->ft_print);
	free(info);
	while (index < philo_tab)
	{
		free(philo[index]);
		index++;
	}
	free(philo);
}

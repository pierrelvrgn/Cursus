/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 08:01:58 by plavergn          #+#    #+#             */
/*   Updated: 2022/03/27 08:43:35 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
	Includes
*/

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

/*
	Structures
*/
typedef struct s_info
{
	size_t	nb_philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	each_eat;
}			t_info;

typedef struct s_philo
{
	int				index;
	int				each_eat;
	size_t			time;
	size_t			last_eat;
	int				eat;
	int				sleep;
	t_info			*info;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
}			t_philo;


/*
	Prototypes
*/

int		ft_atoi(const char *theString);
void	*ft_eat(t_philo **philo);
void	*ft_sleep(t_philo **philo);
void	*ft_think(t_philo **philo);
void	*use_thread_pair(void *arg);
void	*use_thread_odd(void *arg);
void	init_philo_pair(t_philo **philo, int index);
void	init_philo_odd(t_philo **philo, int index);

#endif

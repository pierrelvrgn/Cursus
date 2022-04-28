/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 10:57:37 by plavergn          #+#    #+#             */
/*   Updated: 2022/04/12 13:11:27 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_info
{
	size_t			nb_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			max_eat;
	size_t			start;
	size_t			dead;
	pthread_mutex_t	**fork;
	size_t			*fork_bool;
	pthread_mutex_t	*ft_print;
}		t_info;

typedef struct s_philo
{
	size_t			index;
	size_t			fork_bool_right;
	size_t			fork_bool_left;
	size_t			each_eat;
	size_t			eat;
	size_t			sleep;
	size_t			think;
	size_t			last_eat;
	t_info			*info;
	pthread_t		*thread;
	pthread_mutex_t	*ft_print;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*fork_left;
}			t_philo;

int		ft_atoi(const char *str);
int		init_philo(t_philo **philo, t_info *info);

int		init_all(char **argv, int argc);
int		all_alive(t_philo *philo, t_info *info);
void	ft_free(int philo_tab, t_info *info, t_philo **philo);
int		init_fork(t_info *info);
int		init_info(t_info *info, char **argv, int argc);
int		init_philo_variable(t_philo **philo, t_info *info);
void	start_thread(t_philo *philo);
size_t	ft_get_time(void);
void	ft_ms_sleep(size_t time, t_philo *philo);
void	*use_thread(void *arg);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
int		is_alive_2(t_philo **philo, t_info *info);
void	ft_putstr(char *str, unsigned int a, unsigned int b, t_philo *philo);

#endif

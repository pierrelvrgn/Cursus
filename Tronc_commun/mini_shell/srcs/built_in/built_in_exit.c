/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 08:23:08 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/24 17:00:11 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	mini_check_raw_arg(char *raw_arg)
{
	size_t	a;
	int		sign;

	a = 0;
	sign = 0;
	if (!raw_arg)
		return (1);
	if (ft_big_atol(raw_arg) > INT_MAX || ft_big_atol(raw_arg) < INT_MIN)
		return (2);
	while (raw_arg[a])
	{
		if (!ft_isdigit(raw_arg[a]))
		{
			if (sign == 0 && (raw_arg[a] == '-' || raw_arg[a] == '+'))
				sign = 1;
			else if (sign == 1 && (raw_arg[a] == '-' || raw_arg[a] == '+'))
				return (2);
			else if (raw_arg[a] == ' ' && raw_arg[a + 1] != '\0')
				return (3);
			else
				return (2);
		}
		a++;
	}
	return (0);
}

int	mini_exit_built_in(t_master *master, char *raw_arg)
{
	t_env	*env_var;
	int		check;

	check = mini_check_raw_arg(raw_arg);
	env_var = mini_get_env_var(master->envdata, "SHLVL");
	if (!env_var)
		env_var = mini_set_env_var(master->envdata, "SHLVL", "1");
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (!check)
		g_mini_errno = ft_atoi(raw_arg);
	else if (check == 1)
		g_mini_errno = 0;
	else if (check > 1)
	{
		if (check == 2)
			mini_error(E_EXIT_NUM, NULL, EINVAL);
		else
			mini_error(E_ARG2, NULL, E2BIG);
		g_mini_errno = 255;
		mini_change_env_var_value(master->envdata, "SHLVL", "1");
	}
	mini_end_of_program(master);
	ft_termios_handler(1);
	exit(g_mini_errno);
	return (g_mini_errno);
}

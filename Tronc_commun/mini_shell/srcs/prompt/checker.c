/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 08:14:20 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/24 08:15:09 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*check_var(t_master *master, char *str)
{
	int		i;
	int		quote;

	i = 0;
	quote = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\'')
			quote++;
		if (str[i] == '$' && quote % 2 == 0)
			str = mini_expand_env_var(master->envdata, str, i);
		i++;
	}
	return (str);
}

int	check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			if (str[i] == '\n')
			{
				free(str);
				return (1);
			}
			else
				return (0);
		}
		i++;
	}
	free(str);
	return (1);
}

int	check_return(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
	{
		free(str);
		return (1);
	}
	else
	{
		if (check_space(str) == 1)
			return (1);
		else
			return (0);
	}
	return (0);
}

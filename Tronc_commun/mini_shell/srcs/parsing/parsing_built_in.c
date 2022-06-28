/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_built_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:32:19 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/24 17:11:38 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	count_arg_echo(char *str)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '"')
			len++;
		i++;
	}
	return (len);
}

char	*put_without_d_q(char *str, char *split, int len)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	split = malloc(sizeof(char) * (len + 1));
	if (!split)
	{
		mini_error(E_MALLOC, NULL, ENOMEM);
		return (NULL);
	}
	while (str[i])
	{
		if (str[i] != '"' && str[i] != '\'')
		{
			split[a] = str[i];
			a++;
		}
		i++;
	}
	split[a] = '\0';
	return (split);
}

int	echo_n(char *str, int i)
{
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '-' && str[i + 1])
	{
		i++;
		while (str[i] && str[i] == 'n')
			i++;
	}
	else if (str[i] == '"' && str[i + 1] == '-')
	{
		i += 2;
		while (str[i] && str[i] != ' ' && str[i] != '"' && str[i] == 'n')
			i++;
	}
	return (i);
}

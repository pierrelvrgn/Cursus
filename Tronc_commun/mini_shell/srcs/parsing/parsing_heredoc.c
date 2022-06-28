/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:00:42 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/24 17:07:51 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*str_do(int i, char *line)
{
	char	*str;
	int		a;

	str = malloc(sizeof(char) * (i + 1));
	if (!str)
	{
		mini_error(E_MALLOC, NULL, ENOMEM);
		return (NULL);
	}
	a = 0;
	i = 0;
	while (line[a])
	{
		if (line[a] == '"' || line[a] == '\'')
			a++;
		else if (line[a])
		{
			str[i] = line[a];
			a++;
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

char	*check_char(char *line)
{
	int		a;
	int		i;

	if (!line)
		return (NULL);
	a = 0;
	i = 0;
	while (line[a])
	{
		if (line[a] == '"' || line[a] == '\'')
			a++;
		else if (line[a])
		{
			a++;
			i++;
		}
	}
	return (str_do(i, line));
}

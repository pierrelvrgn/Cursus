/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 13:43:50 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/24 11:44:07 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	*ouioui(int *tab_index, char *str)
{
	tab_index[0]++;
	while (str[tab_index[0]] && (str[tab_index[0]] == ' '
			|| str[tab_index[0]] == '>'))
		tab_index[0]++;
	tab_index[1] = tab_index[0];
	while (str[tab_index[1]])
		tab_index[1]++;
	return (tab_index);
}

int	*test_norm(int *tab_index, char *str)
{
	tab_index[0]++;
	while (str[tab_index[0]] && str[tab_index[0]] == ' ')
		tab_index[0]++;
	tab_index[1] = tab_index[0];
	while (str[tab_index[1]])
		tab_index[1]++;
	return (tab_index);
}

char	*init_split(char *str, int *tab_index)
{
	char	*tmp;

	while (str[tab_index[0]] && str[tab_index[0]] != '>')
		tab_index[0]++;
	tmp = malloc(sizeof(char) * (tab_index[0] + 1));
	if (!tmp)
	{
		mini_error(E_MALLOC, NULL, ENOMEM);
		return (NULL);
	}
	tmp[tab_index[0]] = '\0';
	tab_index[1] = tab_index[0];
	tab_index[0] = 0;
	while (tab_index[0] < tab_index[1])
	{
		tmp[tab_index[0]] = str[tab_index[0]];
		tab_index[0]++;
	}
	return (tmp);
}

int	skip_space(int i, char *str)
{
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int	check_d_quote(char *str, int i)
{
	int	index;

	index = 0;
	while (str[index] && index < i)
	{
		if (str[index] == '"')
			return (0);
		index++;
	}
	return (1);
}

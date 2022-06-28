/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_redir_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:45:17 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/26 08:08:29 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*test_split(char *split, char *str, int *tab_index)
{
	int	i;

	i = tab_index[1];
	split = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!split)
	{
		mini_error(E_MALLOC, NULL, ENOMEM);
		return (NULL);
	}
	tab_index[0] = tab_index[0] - tab_index[1];
	tab_index[1] = 0;
	while (str[tab_index[0]] && str[tab_index[0]] == ' ')
		tab_index[0]++;
	while (str[tab_index[0]] && str[tab_index[0]] != ' ')
	{
		split[tab_index[1]] = str[tab_index[0]];
		tab_index[1]++;
		tab_index[0]++;
	}
	split[tab_index[1]] = '\0';
	return (split);
}

int	*next_arg(char *str, int *tab_index, char c)
{
	while (str[tab_index[0]] && str[tab_index[0]] != c)
	{
		tab_index[1]++;
		tab_index[0]++;
	}
	return (tab_index);
}

int	*init_tab_index(void)
{
	int	*tab_index;

	tab_index = malloc(sizeof(int) * 2);
	if (!tab_index)
	{
		mini_error(E_MALLOC, NULL, ENOMEM);
		return (NULL);
	}
	tab_index[0] = 0;
	tab_index[1] = 0;
	return (tab_index);
}

int	*next_arg_base_fd(int *tab_index, char *str)
{
	while (str[tab_index[0]] && str[tab_index[0]] == ' ')
		tab_index[0]--;
	while (str[tab_index[0]] && ft_ischarset(str[tab_index[0]], BASEDEC))
		tab_index[0]--;
		tab_index[0]++;
	while (str[tab_index[0]] && ft_ischarset(str[tab_index[0]], BASEDEC))
	{
		tab_index[1]++;
		tab_index[0]++;
	}
	return (tab_index);
}

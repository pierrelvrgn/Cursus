/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pre_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 10:08:45 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/26 08:42:34 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	pipe_check(char *str, char *dest, int *tab_index, t_master *master)
{
	int	i;
	int	a;

	i = tab_index[0];
	a = tab_index[1];
	if (str[i] == '|' && check_d_quote(str, i))
	{
		dest = un_dblequote(ft_substr(str, a, i - a - 1));
		if (init_cmd(str, dest, master))
		{
			free(dest);
			return (1);
		}
		free(dest);
		a = i + 2;
	}
	return (a);
}

int	check_base_fd(char *str, int i)
{
	if ((i > 0 && ft_ischarset(str[i - 1], BASEDEC))
		|| (str[i + 1] && str[i + 1] == '>'))
	{
		if (i > 0 && ft_ischarset(str[i - 1], BASEDEC))
		{
			i--;
			while (i > 0 && str[i] && ft_ischarset(str[i], BASEDEC))
				i--;
			if (i > 0)
				i++;
		}
	}
	return (i);
}

int	skip_redir(char *str, int i, int *tab_index)
{
	if (i != tab_index[0])
	{
		while (str[i] && str[i] != '>')
			i++;
		while (str[i] && str[i] == '>')
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		while (str[i] && str[i] != '|' && str[i] != '>' && str[i] != ' ')
			i++;
	}
	else
	{
		while (str[i] && str[i] == '>')
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		while (str[i] && str[i] != '|' && str[i] != '>' && str[i] != ' ')
			i++;
	}
	return (i);
}

int	redir_check(char *str, char *dest, int *tab_index, t_master *master)
{
	int		i;
	int		a;
	char	*tmp;

	i = tab_index[0];
	a = tab_index[1];
	if (str[i] == '>' && check_d_quote(str, i))
	{
		i = check_base_fd(str, i);
		a = i;
		if (a > tab_index[1])
		{
			tmp = un_dblequote(ft_substr(str, tab_index[1], a - tab_index[1]));
			init_cmd(str, tmp, master);
			free(tmp);
		}
		i = skip_redir(str, i, tab_index);
		dest = un_dblequote(ft_substr(str, a, i - a));
		init_cmd(str, dest, master);
		free(dest);
		if (!str[i])
			return (-1);
		a = skip_space(i, str);
	}
	return (a);
}

int	end_check(char *str, char *dest, int *tab_index, t_master *master)
{
	int	i;
	int	a;

	i = tab_index[0];
	a = tab_index[1];
	if (str[i + 1] == '\0' && tab_index[1] > -1)
	{
		dest = un_dblequote(ft_substr(str, a, i - a + 1));
		if (init_cmd(str, dest, master))
		{
			free(dest);
			return (1);
		}
		free(dest);
	}
	return (a);
}

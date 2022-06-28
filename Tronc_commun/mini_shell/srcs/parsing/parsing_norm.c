/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:31:45 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/26 09:56:26 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_fd_and_redir(char *dest)
{
	int	i;

	i = 0;
	while (dest[i] && ft_ischarset(dest[i], BASEDEC))
		i++;
	if (dest[i] == '>')
		return (1);
	else
		return (0);
	return (0);
}

int	init_cmd(char *str, char *dest, t_master *master)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (mini_error(E_MALLOC, NULL, ENOMEM));
	cmd->raw = ft_strdup(str);
	if (check_fd_and_redir(dest))
		init_cmd_redir(dest, master, cmd);
	else
	{
		if (!ft_ischarset('|', str))
		{
			if (!check_export(str, master, cmd))
				init_cmd_no_redir(dest, master, cmd);
		}
		else
			init_cmd_no_redir(dest, master, cmd);
	}
	return (0);
}

int	check_nb_dq(char *str)
{
	int	i;
	int	d_q;

	i = 0;
	d_q = 0;
	while (str[i])
	{
		if (str[i] == '"')
			d_q++;
		i++;
	}
	return (d_q);
}

char	*un_dblequote(char *str)
{
	int		i;
	int		a;
	char	*dest;

	i = 0;
	a = 0;
	dest = malloc(sizeof(char) * (ft_strlen(str) - check_nb_dq(str) + 1));
	if (!dest)
	{
		mini_error(E_MALLOC, NULL, ENOMEM);
		return (NULL);
	}
	while (str[i])
	{
		if (str[i] != '"')
		{
			dest[a] = str[i];
			a++;
		}
		i++;
	}
	dest[a] = '\0';
	free(str);
	return (dest);
}

char	*pre_sort(char *str, t_master *master)
{
	int		*tab_index;
	char	*dest;
	int		tmp;

	tab_index = init_tab_index();
	tmp = 0;
	dest = NULL;
	str = remove_all(str);
	while (str[tab_index[0]])
	{
		tmp = tab_index[1];
		tab_index[1] = redir_check(str, dest, tab_index, master);
		if (tab_index[1] == -1)
			break ;
		tab_index[1] = pipe_check(str, dest, tab_index, master);
		tab_index[1] = end_check(str, dest, tab_index, master);
		if (tab_index[1] > tmp)
			tab_index[0] = tab_index[1];
		else
			tab_index[0]++;
	}
	free(tab_index);
	return (str);
}

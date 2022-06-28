/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 08:12:58 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/24 08:13:51 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	*check_heredoc(char *str, int *tab_index)
{
	tab_index[0] += 2;
	while (str[tab_index[0]] && str[tab_index[0]] == ' ')
		tab_index[0]++;
	tab_index[1] = tab_index[0];
	while (str[tab_index[0]] && str[tab_index[0]] != ' ')
		tab_index[0]++;
	return (tab_index);
}

int	*check_herefile(char *str, int *tab_index)
{
	tab_index[0]++;
	while (str[tab_index[0]] && str[tab_index[0]] == ' ')
		tab_index[0]++;
	tab_index[1] = tab_index[0];
	while (str[tab_index[0]] && str[tab_index[0]] != ' ')
		tab_index[0]++;
	return (tab_index);
}

int	check_access(char *arg, int heredoc)
{
	if (access(arg, F_OK) == -1)
		heredoc = mini_error(E_ACCESS_F, arg, EACCES) * -1;
	else if (access(arg, R_OK) == -1)
		heredoc = mini_error(E_ACCESS_R, arg, EACCES) * -1;
	else
		heredoc = open(arg, O_RDWR);
	return (heredoc);
}

int	mini_handle_heredoc(char *str, int *tab_index, char **arg, t_master *master)
{
	int	heredoc;

	heredoc = -2;
	*arg = ft_substr(str, tab_index[1], tab_index[0] - tab_index[1]);
	heredoc = start_heredoc(*arg, master);
	free (*arg);
	return (heredoc);
}

int	mini_handle_fd_link(char *str, int *tab_index, char **arg)
{
	int	heredoc;

	heredoc = -2;
	*arg = ft_substr(str, tab_index[1], tab_index[0] - tab_index[1]);
	heredoc = check_access(*arg, heredoc);
	free (*arg);
	return (heredoc);
}

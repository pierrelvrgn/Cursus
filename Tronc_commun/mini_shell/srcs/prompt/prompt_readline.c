/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_readline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:59:48 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/26 08:53:24 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_heredoc(char *str, t_master *master)
{
	int		heredoc;
	char	*arg;
	int		*tab_index;

	tab_index = init_tab_index();
	heredoc = -2;
	while (str[tab_index[0]])
	{
		if (str[tab_index[0]] == '<' && str[tab_index[0] + 1] == '<')
		{
			tab_index = check_heredoc(str, tab_index);
			heredoc = mini_handle_heredoc(str, tab_index, &arg, master);
		}
		else if (str[tab_index[0]] == '<' && str[tab_index[0] + 1] != '<')
		{
			tab_index = check_herefile(str, tab_index);
			heredoc = mini_handle_fd_link(str, tab_index, &arg);
		}
		else
			tab_index[0]++;
	}
	free(tab_index);
	return (heredoc);
}

void	mini_exec_fd_link(t_master *master, int heredoc)
{
	t_cmd	*cmd;

	cmd = master->execdata->lst->content;
	if (heredoc == -2)
		master->fdstruct->fd_link = dup(STDIN_FILENO);
	else
		master->fdstruct->fd_link = heredoc;
	mini_exec_loop(master);
}

void	check_exit_str_1(char *str, t_master *master)
{
	if (!ft_strncmp(str, "exit",
			ft_get_highest(ft_strlen(str), ft_strlen("exit"))))
		mini_exit_built_in(master, NULL);
}

char	*norm_readline(t_master *master, char *str)
{
	master->execdata->lst = NULL;
	ft_termios_handler(0);
	master->execdata->lst_size = 0;
	search_signal();
	str = readline("Morning-shell ➡ ");
	ft_termios_handler(1);
	check_str_empty(str);
	add_history(str);
	str = check_var(master, str);
	return (str);
}

int	ft_readline(t_master *master)
{
	char	*str;
	int		heredoc;

	str = NULL;
	str = norm_readline(master, str);
	if (check_return(str))
		return (1);
	if (mini_check_line(str))
	{
		free(str);
		return (1);
	}
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	heredoc = ft_heredoc(str, master);
	str = pre_sort(str, master);
	master->execdata->start = master->execdata->lst;
	check_exit_str_1(str, master);
	if (str[0])
		mini_exec_fd_link(master, heredoc);
	mini_free_execdata_list(master->execdata);
	free(str);
	return (1);
}

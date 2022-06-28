/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:38:32 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/25 15:12:56 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	handler_here(int byte)
{
	(void)byte;
	ft_dprintf(STDOUT_FILENO, "\n");
	exit(EXIT_SUCCESS);
}

void	search_signal_heredoc(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handler_here);
}

void	handler_child(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}

void	handler_cat(int byte)
{
	if (byte == SIGINT)
		ft_dprintf(STDOUT_FILENO, "\n");
	else if (byte == SIGQUIT)
	{
		ft_dprintf(STDOUT_FILENO, "Quit: 3\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 07:31:27 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/24 17:07:51 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_termios_handler(int end)
{
	struct termios			termios_p;
	static struct termios	termios_before;
	int						fd_term;

	fd_term = ttyslot();
	if (end == 1)
	{
		tcsetattr(fd_term, TCSANOW, &termios_before);
		return ;
	}
	tcgetattr(fd_term, &termios_before);
	termios_p = termios_before;
	termios_p.c_cc[VQUIT] = 0;
	termios_p.c_lflag &= ~ECHOCTL;
	tcsetattr(fd_term, TCSANOW, &termios_p);
}

void	handler(int byte)
{
	(void)byte;
	rl_on_new_line();
	rl_replace_line("", 0);
	ft_dprintf(0, "\n");
	rl_redisplay();
}

void	search_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handler);
}

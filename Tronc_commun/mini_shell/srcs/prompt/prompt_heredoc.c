/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 08:36:49 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/23 16:41:18 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	mini_check_limiter(char *prompt, char *limiter)
{
	size_t	a;

	a = 0;
	if (!prompt || !limiter)
		return (0);
	while (prompt[a] != '\0' && limiter[a])
	{
		if (prompt[a] != limiter[a])
			return (1);
		a++;
	}
	if (prompt[a] == '\0' && limiter[a] == '\0')
		return (0);
	return (1);
}

void	norminette_src(char *prompt, char *str, int pipe_fd, t_master *master)
{
	while (1)
	{
		search_signal_heredoc();
		prompt = readline(">");
		if (!mini_check_limiter(prompt, str))
			break ;
		prompt = check_var(master, prompt);
		if (write(pipe_fd, prompt, ft_strlen(prompt)) == -1)
			mini_error(E_WRITE, NULL, EPERM);
		if (write(pipe_fd, "\n", 1) == -1)
			mini_error(E_WRITE, NULL, EPERM);
		free (prompt);
	}
	prompt = NULL;
}

int	mini_heredoc(char *limiter, t_master *master)
{
	char	*prompt;
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		return (mini_error(E_PIPE, NULL, ENOMEM));
	pid = fork();
	if (pid < 0)
		return (1);
	else if (pid == 0)
	{
		close(pipe_fd[0]);
		prompt = NULL;
		norminette_src(prompt, limiter, pipe_fd[1], master);
		close (pipe_fd[1]);
		exit(EXIT_SUCCESS);
	}
	else
		close(pipe_fd[1]);
	wait(NULL);
	return (pipe_fd[0]);
}

int	ft_strlen_char(char *str, char c, int start)
{
	while (str[start] && str[start] != c)
		start++;
	return (start);
}

int	start_heredoc(char *limiter, t_master *master)
{
	int		fd;

	signal(SIGINT, SIG_IGN);
	fd = mini_heredoc(limiter, master);
	return (fd);
}

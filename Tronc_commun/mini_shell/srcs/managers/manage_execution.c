/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 11:07:18 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/23 16:41:18 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	mini_dup_handler(t_master *master, int pipe_fd[2], int last, int btin)
{
	if (!btin)
		if (close(pipe_fd[0]) == -1)
			return (mini_error(E_CLOSE, NULL, EBADF));
	if (dup2(master->fdstruct->fd_link, STDIN_FILENO) == -1)
		return (mini_error(E_DUP2, NULL, EBADF));
	if (last)
	{
		if (!btin)
		{
			if (close (pipe_fd[1]) == -1)
				return (mini_error(E_CLOSE, NULL, EBADF));
		}
		if (dup2(master->fdstruct->fd_out, STDOUT_FILENO) == -1)
			return (mini_error(E_DUP2, NULL, EBADF));
	}
	else
	{
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			return (mini_error(E_DUP2, NULL, EBADF));
	}
	return (0);
}

int	mini_close_child_process(int pipe_fd, int fd_link)
{
	if (close(pipe_fd) == -1)
		return (mini_error(E_CLOSE, NULL, EBADF));
	if (close(fd_link) == -1)
		return (mini_error(E_CLOSE, NULL, EBADF));
	return (0);
}

int	mini_check_cmd(char *cmd)
{
	if (!cmd)
		return (mini_error(E_INVAL_ID, NULL, ENOENT));
	return (0);
}

//Fait tourner chaque path avec la commande pour vérifier son existence
char	*mini_check_cmd_paths(char **paths, char *cmd)
{
	char	*tmp;
	size_t	a;

	a = 0;
	if (mini_check_cmd(cmd))
		return (NULL);
	if (!access(cmd, F_OK))
		return (ft_strdup(cmd));
	if (!paths)
	{
		mini_error(E_PATH, NULL, EINVAL);
		return (NULL);
	}
	while (paths[a])
	{
		tmp = ft_strjoin(paths[a], cmd);
		if (!access(tmp, F_OK))
			return (tmp);
		free (tmp);
		a++;
	}
	mini_error(E_ACCESS_F, cmd, ENOENT);
	return (NULL);
}

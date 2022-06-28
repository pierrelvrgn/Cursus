/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 08:04:15 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/23 08:27:53 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	mini_built_in_part_one(t_master *master, t_cmd *cmd)
{
	if (!ft_strncmp(cmd->split[0], "echo",
			ft_get_highest(cmd->len_cmd, ft_strlen("echo"))))
		return (mini_echo_built_in(cmd->split));
	if (!ft_strncmp(cmd->split[0], "pwd",
			ft_get_highest(cmd->len_cmd, ft_strlen("pwd"))))
		return (mini_pwd_built_in());
	if (!ft_strncmp(cmd->split[0], "env",
			ft_get_highest(cmd->len_cmd, ft_strlen("env"))))
		return (mini_env_built_in(master->envdata, cmd));
	if (!ft_strncmp(cmd->split[0], "exit",
			ft_get_highest(cmd->len_cmd, ft_strlen("exit"))))
		return (mini_exit_built_in(master, cmd->split[1]));
	if (!ft_strncmp(cmd->split[0], "cd",
			ft_get_highest(cmd->len_cmd, ft_strlen("cd"))))
		return (mini_cd_built_in(master->envdata, cmd->split[1]));
	return (-1);
}

int	mini_built_in_part_two(t_master *master, t_cmd *cmd, int a)
{
	if (!ft_strncmp(cmd->split[0], "export",
			ft_get_highest(cmd->len_cmd, ft_strlen("export"))))
	{
		if (!cmd->split[1])
			return (mini_export_built_in(master->envdata, NULL));
		while (cmd->split[a])
		{
			mini_export_built_in(master->envdata, cmd->split[a]);
			a++;
		}
		return (0);
	}
	if (!ft_strncmp(cmd->split[0], "unset",
			ft_get_highest(cmd->len_cmd, ft_strlen("unset"))))
	{
		while (cmd->split[a])
		{
			mini_unset_built_in(master->envdata, cmd->split[a]);
			a++;
		}
		return (0);
	}
	return (-1);
}

int	mini_btin_hub(t_master *master, t_cmd *cmd, int pipe_fd[2], int last)
{
	if (mini_dup_handler(master, pipe_fd, last, 1))
		return (-1);
	if (!ft_strncmp(cmd->split[0], "echo",
			ft_get_highest(cmd->len_cmd, ft_strlen("echo")))
		|| !ft_strncmp(cmd->split[0], "pwd",
			ft_get_highest(cmd->len_cmd, ft_strlen("pwd")))
		|| !ft_strncmp(cmd->split[0], "env",
			ft_get_highest(cmd->len_cmd, ft_strlen("env")))
		|| !ft_strncmp(cmd->split[0], "exit",
			ft_get_highest(cmd->len_cmd, ft_strlen("exit")))
		|| !ft_strncmp(cmd->split[0], "cd",
			ft_get_highest(cmd->len_cmd, ft_strlen("cd"))))
		return (mini_built_in_part_one(master, cmd));
	else if (!ft_strncmp(cmd->split[0], "export",
			ft_get_highest(cmd->len_cmd, ft_strlen("export")))
		|| !ft_strncmp(cmd->split[0], "unset",
			ft_get_highest(cmd->len_cmd, ft_strlen("unset"))))
		return (mini_built_in_part_two(master, cmd, 1));
	return (-1);
}

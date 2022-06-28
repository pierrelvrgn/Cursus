/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:33:33 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/24 17:07:51 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_builtin(char *split, int len_cmd)
{
	if (!ft_strncmp(split, "echo",
			ft_get_highest(len_cmd, ft_strlen("echo"))))
		return (1);
	if (!ft_strncmp(split, "pwd",
			ft_get_highest(len_cmd, ft_strlen("pwd"))))
		return (1);
	if (!ft_strncmp(split, "env",
			ft_get_highest(len_cmd, ft_strlen("env"))))
		return (1);
	if (!ft_strncmp(split, "exit",
			ft_get_highest(len_cmd, ft_strlen("exit"))))
		return (1);
	if (!ft_strncmp(split, "export",
			ft_get_highest(len_cmd, ft_strlen("export"))))
		return (1);
	if (!ft_strncmp(split, "unset",
			ft_get_highest(len_cmd, ft_strlen("unset"))))
		return (1);
	if (!ft_strncmp(split, "cd",
			ft_get_highest(len_cmd, ft_strlen("cd"))))
		return (1);
	return (0);
}

int	check_token_id(char *split, int len_cmd)
{
	int	token_id;
	int	i;

	i = 0;
	if (ft_strncmp(split, ">", ft_get_highest(len_cmd, ft_strlen(">"))) == 0)
		token_id = IDT_REDIR;
	else if (check_builtin(split, len_cmd) == 1)
		token_id = IDT_BTIN;
	else
		token_id = IDT_CMD;
	return (token_id);
}

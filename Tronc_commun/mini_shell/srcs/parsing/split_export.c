/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 12:56:14 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/26 09:52:36 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	do_export(char *str, t_master *master)
{
	t_cmd	*cmd;
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(str, ' ');
	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (mini_error(E_MALLOC, NULL, ENOMEM));
	cmd->raw = ft_strdup(str);
	if (tmp[0])
		cmd->len_cmd = ft_strlen(tmp[0]);
	cmd->token_id = IDT_BTIN;
	cmd->split = split_export(str);
	ft_free_split(tmp);
	ft_lstadd_back(&master->execdata->lst, ft_lstnew(cmd));
	master->execdata->lst_size++;
	return (1);
}

int	check_export(char *str, t_master *master, t_cmd *cmd)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(str, ' ');
	if (!ft_strncmp(tmp[0], "export",
			ft_get_highest(ft_strlen(tmp[0]), ft_strlen("export"))))
	{
		ft_free_split(tmp);
		free (cmd->raw);
		free (cmd);
		return (do_export(str, master));
	}
	ft_free_split(tmp);
	return (0);
}

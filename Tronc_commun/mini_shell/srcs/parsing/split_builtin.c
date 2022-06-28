/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:24:08 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/25 16:01:02 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**split_pwd(char *dest)
{
	char	**split;

	split = split_malloc(2);
	if (!split)
		return (NULL);
	split[0] = ft_strdup(dest);
	split[1] = NULL;
	return (split);
}

char	**split_cd(char *str, char *dest, t_cmd *cmd)
{
	int		i;
	int		a;

	a = 0;
	i = ft_strlen(dest);
	cmd->split = split_malloc(3);
	if (!cmd->split)
		return (NULL);
	cmd->split[0] = ft_strdup(dest);
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
	{
		a++;
		i++;
	}
	cmd->split[1] = ft_substr(str, i - a, a);
	if (!cmd->split[1][0])
	{
		free (cmd->split[1]);
		cmd->split[1] = NULL;
	}
	cmd->split[2] = NULL;
	return (cmd->split);
}

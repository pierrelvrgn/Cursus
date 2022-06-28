/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_built_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:35:35 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/24 17:09:37 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**split_malloc(int nb)
{
	char	**split;

	split = malloc(sizeof(char *) * (nb));
	if (!split)
	{
		mini_error(E_MALLOC, NULL, ENOMEM);
		return (NULL);
	}
	return (split);
}

char	**split_exit(char *str, char *dest, t_cmd *cmd)
{
	char	*source;
	int		i;
	int		a;

	a = 0;
	i = ft_strlen(dest);
	source = cmd->raw;
	while (source[i])
	{
		if (source[i] == '|')
		{
			exit(EXIT_FAILURE);
		}
		i++;
	}
	cmd->split = ft_split(str, ' ');
	return (cmd->split);
}

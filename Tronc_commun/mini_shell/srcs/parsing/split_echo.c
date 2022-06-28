/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 08:15:46 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/25 13:09:41 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	init_split_echo(t_cmd *cmd, char *dest, char *str, int j)
{
	cmd->split[0] = ft_strdup(dest);
	cmd->len_cmd = count_arg_echo(str);
	cmd->split[j] = put_without_d_q(str, cmd->split[j], cmd->len_cmd + 1);
	cmd->split[j + 1] = NULL;
}

int	mini_increment_i(char *str, int i)
{
	if (str[i])
		if (str[i + 1])
			i++;
	return (i);
}

char	**split_echo(char *str, char *dest, t_cmd *cmd)
{
	int	i;
	int	j;

	j = 1;
	i = echo_n(str, ft_int_strchr(str, ' ') + 1);
	if (i > 0 && str[i - 1] == 'n'
		&& (str[i] == ' ' || str[i] == '"' || !str[i]))
	{
		i = mini_increment_i(str, i);
		cmd->split = split_malloc(4);
		if (!cmd->split)
			return (NULL);
		cmd->split[1] = ft_strdup("-n");
		j = 2;
	}
	else
	{
		i = cmd->len_cmd;
		cmd->split = split_malloc(3);
		if (!cmd->split)
			return (NULL);
	}
	i = skip_space(i, str);
	init_split_echo(cmd, dest, &str[i], j);
	return (cmd->split);
}

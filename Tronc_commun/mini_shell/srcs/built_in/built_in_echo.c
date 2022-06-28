/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_echo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:15:51 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/25 13:04:48 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	mini_echo_built_in(char **split)
{
	int	option;

	option = 0;
	if (!ft_strncmp(split[1], "-n", ft_get_highest(2, ft_strlen(split[1]))))
		option = 1;
	if (option)
	{
		if (!split[2])
			ft_dprintf(STDOUT_FILENO, "");
		else
			ft_dprintf(STDOUT_FILENO, "%s", split[2]);
	}
	else
		ft_dprintf(STDOUT_FILENO, "%s\n", split[1]);
	return (g_mini_errno = 0);
}

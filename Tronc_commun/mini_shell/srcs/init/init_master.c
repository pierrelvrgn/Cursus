/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_master.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:58:55 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/23 16:41:18 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	mini_init_master(t_master *master, char **env)
{
	master->envdata = ft_calloc(1, sizeof(t_envdata));
	if (!master->envdata)
		return (mini_error(E_MALLOC, NULL, ENOMEM));
	master->fdstruct = ft_calloc(1, sizeof(t_fdstruct));
	if (!master->fdstruct)
		return (mini_error(E_MALLOC, NULL, ENOMEM));
	master->execdata = ft_calloc(1, sizeof(t_execdata));
	if (!master->execdata)
		return (mini_error(E_MALLOC, NULL, ENOMEM));
	if (mini_init_envdata(master->envdata, env))
		return (1);
	if (mini_init_fdstruct(master->fdstruct))
		return (1);
	return (0);
}

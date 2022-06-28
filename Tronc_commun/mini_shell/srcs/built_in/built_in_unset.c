/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:04:20 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/25 09:02:05 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	mini_check_raw_arg(char *raw_arg)
{
	size_t	a;

	a = 0;
	if ((raw_arg[0] < 'A' || (raw_arg[0] > 'Z' && raw_arg[0] < 'a')
			|| raw_arg[0] > 'z') && raw_arg[0] != '_')
		return (1);
	while (raw_arg[a])
	{
		if (raw_arg[a] < '0' || (raw_arg[a] > '9' && raw_arg[a] < 'A')
			|| (raw_arg[a] > 'Z' && raw_arg[a] < '_')
			|| (raw_arg[a] > '_' && raw_arg[a] < 'a') || raw_arg[a] > 'z')
			return (1);
		a++;
	}
	return (0);
}

int	mini_unset_built_in(t_envdata *envdata, char *raw_arg)
{
	t_env	*env_var;
	void	*previous_link;
	size_t	arglen;

	env_var = NULL;
	previous_link = NULL;
	envdata->lst = envdata->start;
	if (!raw_arg || !raw_arg[0])
		return (1);
	if (mini_check_raw_arg(raw_arg))
		return (mini_error(E_INVAL_ID, raw_arg, EINVAL));
	arglen = ft_strlen(raw_arg);
	while (envdata->lst)
	{
		env_var = envdata->lst->content;
		if (!ft_strncmp(env_var->name, raw_arg,
				ft_get_highest(arglen, env_var->name_len)))
		{
			mini_delete_env_var(envdata, previous_link, envdata->lst);
			break ;
		}
		previous_link = envdata->lst;
		envdata->lst = envdata->lst->next;
	}
	return (g_mini_errno = 0);
}

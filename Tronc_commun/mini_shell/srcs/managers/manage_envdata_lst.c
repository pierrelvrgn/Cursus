/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_envdata_lst.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 08:43:12 by ljohnson          #+#    #+#             */
/*   Updated: 2022/05/08 09:54:37 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	*mini_get_env_var_by_index(t_envdata *envdata, int index)
{
	t_env	*env_var;

	envdata->lst = envdata->start;
	while (envdata->lst)
	{
		env_var = envdata->lst->content;
		if (env_var->index == index)
			return (env_var);
		envdata->lst = envdata->lst->next;
	}
	return (NULL);
}

void	mini_reset_env_list_index(t_envdata *envdata)
{
	t_env	*env_var;

	envdata->lst = envdata->start;
	while (envdata->lst)
	{
		env_var = envdata->lst->content;
		env_var->index = -1;
		envdata->lst = envdata->lst->next;
	}
}

void	mini_set_env_list_index(t_envdata *envdata)
{
	t_env	*env_var;
	t_env	*cmp_var;
	size_t	count;
	int		highest_len;

	count = 0;
	highest_len = 0;
	while (count < envdata->lst_size)
	{
		env_var = mini_get_env_var_by_index(envdata, -1);
		if (!env_var)
			break ;
		env_var->index = 0;
		envdata->lst = envdata->start;
		while (envdata->lst)
		{
			cmp_var = envdata->lst->content;
			highest_len = ft_get_highest(env_var->name_len, cmp_var->name_len);
			if (ft_strncmp(env_var->name, cmp_var->name, highest_len) > 0)
				env_var->index++;
			envdata->lst = envdata->lst->next;
		}
		count++;
	}
}

char	**mini_convert_lst_to_split(t_envdata *envdata)
{
	t_env	*env_var;
	char	**split;
	size_t	a;

	a = 0;
	envdata->lst = envdata->start;
	split = ft_calloc(envdata->lst_size + 1, sizeof(char *));
	if (!split)
		return (NULL);
	while (a < envdata->lst_size && envdata->lst)
	{
		env_var = envdata->lst->content;
		split[a] = ft_strdup(env_var->name);
		if (env_var->value)
		{
			split[a] = ft_strfreejoin(split[a], ft_strdup("="));
			split[a] = ft_strfreejoin(split[a], ft_strdup(env_var->value));
		}
		envdata->lst = envdata->lst->next;
		a++;
	}
	split[a] = NULL;
	return (split);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_envdata_vars.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 08:32:24 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/26 10:34:51 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	mini_delete_env_var(t_envdata *envdata, t_list *prev, t_list *current)
{
	t_env	*env_var;

	env_var = current->content;
	if (env_var->name)
		free (env_var->name);
	if (env_var->value)
		free (env_var->value);
	if (prev)
		prev->next = current->next;
	else
		envdata->start = current->next;
	if (current->content)
		free (current->content);
	if (current)
		free (current);
	envdata->lst_size--;
}

void	mini_append_env_var_value(t_envdata *envdata, char *name, char *value)
{
	t_env	*env_var;
	char	*tmp;

	tmp = NULL;
	env_var = mini_get_env_var(envdata, name);
	if (!env_var)
		env_var = mini_set_env_var(envdata, name, value);
	else
	{
		tmp = env_var->value;
		env_var->value = ft_strjoin(env_var->value, value);
		free (tmp);
	}
}

void	mini_change_env_var_value(t_envdata *envdata, char *name, char *value)
{
	t_env	*env_var;

	env_var = mini_get_env_var(envdata, name);
	if (!env_var)
		env_var = mini_set_env_var(envdata, name, value);
	else
	{
		free (env_var->value);
		env_var->value = ft_strdup(value);
	}
}

void	*mini_set_env_var(t_envdata *envdata, char *name, char *value)
{
	t_env	*env_var;

	if (!name)
	{
		mini_error(E_INVAL_ID, NULL, EINVAL);
		return (NULL);
	}
	env_var = ft_calloc(1, sizeof(t_env));
	if (!env_var)
		return (NULL);
	envdata->lst = envdata->start;
	env_var->name = ft_strdup(name);
	env_var->name_len = ft_strlen(env_var->name);
	if (value)
		env_var->value = ft_strdup(value);
	else
		env_var->value = NULL;
	env_var->index = -1;
	ft_lstadd_back(&envdata->lst, ft_lstnew(env_var));
	envdata->lst_size++;
	if (envdata->lst_size == 1)
		envdata->start = envdata->lst;
	return (env_var);
}

void	*mini_get_env_var(t_envdata *envdata, char *name)
{
	t_env	*env_var;
	size_t	name_len;
	size_t	highest_len;

	if (!name)
	{
		mini_error(E_INVAL_ID, NULL, EINVAL);
		return (NULL);
	}
	envdata->lst = envdata->start;
	name_len = ft_strlen(name);
	highest_len = 0;
	while (envdata->lst)
	{
		env_var = envdata->lst->content;
		highest_len = ft_get_highest(name_len, env_var->name_len);
		if (!ft_strncmp(env_var->name, name, highest_len))
			return (env_var);
		envdata->lst = envdata->lst->next;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_envdata.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 08:18:24 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/25 09:02:08 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	mini_init_paths(t_envdata *envdata)
{
	t_env	*env_var;
	char	*tmp;
	size_t	a;

	a = 0;
	tmp = NULL;
	env_var = mini_get_env_var(envdata, "PATH");
	if (!env_var || !env_var->value)
		return (mini_error(E_PATH, NULL, EINVAL));
	envdata->paths = ft_split(env_var->value, ':');
	if (!envdata->paths)
		return (mini_error(E_MALLOC, NULL, ENOMEM));
	while (envdata->paths[a])
	{
		tmp = envdata->paths[a];
		envdata->paths[a] = ft_strjoin(envdata->paths[a], "/");
		free (tmp);
		a++;
	}
	return (0);
}

int	mini_init_env_var(t_envdata *envdata, char *envline)
{
	t_env	*env_var;
	int		sep_index;
	int		len;

	if (!envline)
		return (1);
	sep_index = ft_int_strchr(envline, '=');
	len = ft_strlen(envline);
	env_var = ft_calloc(1, sizeof(t_env));
	if (!env_var)
		return (mini_error(E_MALLOC, NULL, ENOMEM));
	if (sep_index > -1)
	{
		env_var->name = ft_substr(envline, 0, sep_index);
		env_var->value = ft_substr(envline, sep_index + 1, len);
	}
	else
	{
		env_var->name = ft_strdup(envline);
		env_var->value = NULL;
	}
	env_var->name_len = ft_strlen(env_var->name);
	env_var->index = -1;
	ft_lstadd_back(&envdata->lst, ft_lstnew(env_var));
	return (0);
}

int	mini_init_base_vars(t_envdata *envdata)
{
	char	*pwd;

	if (mini_init_env_var(envdata, "SHLVL=1"))
		return (1);
	envdata->start = envdata->lst;
	envdata->lst_size++;
	pwd = getcwd(NULL, 0);
	if (!pwd)
		(mini_error(E_GETCWD, NULL, EINVAL));
	if (!mini_set_env_var(envdata, "PWD", pwd))
		return (mini_error(E_MALLOC, NULL, ENOMEM));
	if (!mini_set_env_var(envdata, "_", "./minishell"))
		return (mini_error(E_MALLOC, NULL, ENOMEM));
	if (!mini_set_env_var(envdata, "OLDPWD", NULL))
		return (mini_error(E_MALLOC, NULL, ENOMEM));
	free (pwd);
	return (0);
}

int	mini_init_envdata(t_envdata *envdata, char **env)
{
	size_t	a;

	a = 0;
	envdata->lst = NULL;
	envdata->lst_size = 0;
	envdata->paths = NULL;
	if (!env || !env[a])
		return (mini_init_base_vars(envdata));
	while (env[a])
	{
		if (mini_init_env_var(envdata, env[a]))
			return (1);
		envdata->lst_size++;
		a++;
	}
	envdata->start = envdata->lst;
	return (0);
}

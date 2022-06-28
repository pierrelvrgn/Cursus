/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:15:37 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/25 15:47:23 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	mini_chdir_home(t_envdata *envdata, char *path, char *old_pwd)
{
	t_env	*env_var;
	char	*new_pwd;

	new_pwd = NULL;
	env_var = mini_get_env_var(envdata, "HOME");
	if (!env_var)
	{
		free (old_pwd);
		return (mini_error(E_HOME, NULL, EINVAL));
	}
	new_pwd = ft_strdup(env_var->value);
	if (path && path[1] == '/')
		new_pwd = ft_strfreejoin(new_pwd, ft_substr(path, 1, ft_strlen(path)));
	if (chdir(new_pwd) == -1)
	{
		free (new_pwd);
		free (old_pwd);
		return (mini_error(E_CHDIR, new_pwd, ENOENT));
	}
	free (new_pwd);
	return (0);
}

int	mini_chdir_oldpwd(t_envdata *envdata, char *old_pwd)
{
	t_env	*env_var;

	env_var = mini_get_env_var(envdata, "OLDPWD");
	if (!env_var || !env_var->value)
	{
		free (old_pwd);
		return (mini_error(E_OLDPWD, NULL, EINVAL));
	}
	if (chdir(env_var->value) == -1)
	{
		free (old_pwd);
		return (mini_error(E_CHDIR, env_var->value, ENOENT));
	}
	return (0);
}

int	mini_check_path(t_envdata *envdata, char *pwd, char *path)
{
	if (!path || !path[0] || path[0] == '~'
		|| (path[0] == '-' && path[1] == '-' && !path[2]))
	{
		if (mini_chdir_home(envdata, path, pwd))
			return (1);
	}
	else if (path[0] == '-' && !path[1])
	{
		if (mini_chdir_oldpwd(envdata, pwd))
			return (1);
	}
	else
	{
		if (chdir(path) == -1)
		{
			free (pwd);
			return (mini_error(E_CHDIR, path, ENOENT));
		}
	}
	return (0);
}

int	mini_cd_built_in(t_envdata *envdata, char *path)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (mini_error(E_GETCWD, NULL, EINVAL));
	if (mini_check_path(envdata, pwd, path))
		return (1);
	mini_change_env_var_value(envdata, "OLDPWD", pwd);
	free (pwd);
	pwd = getcwd(NULL, 0);
	if (!pwd)
		return (mini_error(E_GETCWD, NULL, EINVAL));
	mini_change_env_var_value(envdata, "PWD", pwd);
	free (pwd);
	return (g_mini_errno = 0);
}

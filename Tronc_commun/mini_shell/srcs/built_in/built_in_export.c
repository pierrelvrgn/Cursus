/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:30:41 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/26 09:02:01 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

//Display all vars by alnum order if no arg is given to export
int	mini_export_display(t_envdata *envdata)
{
	t_env	*env_var;
	size_t	count;

	count = 0;
	mini_reset_env_list_index(envdata);
	mini_set_env_list_index(envdata);
	while (count < envdata->lst_size)
	{
		env_var = mini_get_env_var_by_index(envdata, count);
		if (!env_var)
			break ;
		ft_dprintf(1, "declare -x %s", env_var->name);
		if (env_var->value)
			ft_dprintf(1, "=\"%s\"\n", env_var->value);
		else
			ft_putchar_fd('\n', 1);
		count++;
	}
	return (0);
}

//Add an env_var, if it doesn't exist, set it, it it exist, change it
void	mini_add_var(t_envdata *envdata, char *arg, int append)
{
	char	*name;
	char	*value;

	if (append == 1)
		name = ft_substr(arg, 0, ft_int_strchr(arg, '+'));
	else
		name = ft_substr(arg, 0, ft_int_strchr(arg, '='));
	value = ft_substr(arg, ft_int_strchr(arg, '=') + 1, ft_strlen(arg));
	if (append == 1)
		mini_append_env_var_value(envdata, name, value);
	else
		mini_change_env_var_value(envdata, name, value);
	free (name);
	free (value);
}

//Check any character that should not belong to a varname
static int	mini_check_raw_arg(char *raw_arg)
{
	size_t	a;

	a = 0;
	if ((raw_arg[0] < 'A' || (raw_arg[0] > 'Z' && raw_arg[0] < 'a')
			|| raw_arg[0] > 'z') && raw_arg[0] != '_')
		return (-1);
	while (raw_arg[a])
	{
		if (raw_arg[a] < '0' || (raw_arg[a] > '9' && raw_arg[a] < 'A')
			|| (raw_arg[a] > 'Z' && raw_arg[a] < '_')
			|| (raw_arg[a] > '_' && raw_arg[a] < 'a') || raw_arg[a] > 'z')
		{
			if (((raw_arg[a] == '+' && raw_arg[a + 1] == '=')
					|| raw_arg[a] == '=') && a != 0)
				return (a);
			return (-1);
		}
		a++;
	}
	return (a);
}

int	mini_export_built_in(t_envdata *envdata, char *raw_arg)
{
	t_env	*env_var;
	int		sep_index;

	if (!raw_arg || !raw_arg[0])
		return (mini_export_display(envdata));
	env_var = NULL;
	sep_index = mini_check_raw_arg(raw_arg);
	if (sep_index == -1)
		return (mini_error(E_INVAL_ID, raw_arg, EINVAL));
	else if (sep_index == (int)ft_strlen(raw_arg))
	{
		env_var = mini_get_env_var(envdata, raw_arg);
		if (!env_var)
			env_var = mini_set_env_var(envdata, raw_arg, NULL);
	}
	else
	{
		if (raw_arg[sep_index] == '+')
			mini_add_var(envdata, raw_arg, 1);
		else
			mini_add_var(envdata, raw_arg, 0);
	}
	return (g_mini_errno = 0);
}

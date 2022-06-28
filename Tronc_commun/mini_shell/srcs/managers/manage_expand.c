/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 09:58:24 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/17 10:54:46 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*mini_expand_global_var(char *line, int i)
{
	char	*new_line;

	new_line = ft_substr(line, 0, i);
	if (!new_line)
		return (line);
	new_line = ft_strfreejoin(new_line, ft_itoa(g_mini_errno));
	if (!new_line)
		return (line);
	if (ft_count_char(g_mini_errno) == 1)
		i += ft_count_char(g_mini_errno) + 1;
	else
		i += ft_count_char(g_mini_errno);
	new_line = ft_strfreejoin(new_line, ft_substr(line, i, ft_strlen(line)));
	if (!new_line)
		return (line);
	free (line);
	return (new_line);
}

char	*mini_create_new_line(t_env *env_var, char *line, int i)
{
	char	*new_line;

	new_line = ft_substr(line, 0, i);
	if (!new_line)
		return (NULL);
	new_line = ft_strfreejoin(new_line, ft_strdup(env_var->value));
	if (!new_line)
		return (NULL);
	i += env_var->name_len + 1;
	new_line = ft_strfreejoin(new_line, ft_substr(line, i, ft_strlen(line)));
	if (!new_line)
		return (NULL);
	return (new_line);
}

char	*mini_get_varname(char *line, int i)
{
	char	*varname;
	int		a;

	a = i;
	while (line[a] && ft_ischarset(line[a], ENVNAME_CSET))
		a++;
	varname = ft_substr(line, i, a - i);
	if (!varname)
		return (NULL);
	return (varname);
}

char	*mini_expand_env_var(t_envdata *envdata, char *line, int i)
{
	t_env	*env_var;
	char	*varname;
	char	*new_line;

	env_var = NULL;
	varname = NULL;
	new_line = NULL;
	if (!line || !line[0] || !line[i] || line[i] != '$')
		return (line);
	if (line[i] == '$' && line[i + 1] == '?')
		return (mini_expand_global_var(line, i));
	varname = mini_get_varname(line, i + 1);
	if (!varname)
		return (line);
	env_var = mini_get_env_var(envdata, varname);
	free (varname);
	if (!env_var)
		return (line);
	new_line = mini_create_new_line(env_var, line, i);
	if (!new_line)
		return (line);
	free (line);
	return (new_line);
}

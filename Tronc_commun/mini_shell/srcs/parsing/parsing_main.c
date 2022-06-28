/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:07:26 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/23 16:41:18 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	mini_loop_quote(char *line, char quote, int a)
{
	while (line[a] && line[a] != quote)
		a++;
	if (!line[a])
		return (mini_error(E_INVAL_ID, NULL, EINVAL) * -1);
	return (a);
}

int	mini_check_supported_char(char *line, int a)
{
	if (line[a] && ft_ischarset(line[a], "[{()}]\\;&^%#@*,:"))
		return (mini_error(E_INVAL_ID, NULL, EINVAL));
	else if (line[a] && (line[a] == '|' && line[a + 1] == '|'))
		return (mini_error(E_INVAL_ID, NULL, EINVAL));
	else if (line[a] && (line[a] == '&' && line[a + 1] == '&'))
		return (mini_error(E_INVAL_ID, NULL, EINVAL));
	return (0);
}

int	mini_check_syntax(char *line, char symbol, int a)
{
	while (line[a] && line[a] == ' ')
		a++;
	if (!line[a] || (ft_ischarset(line[a], "|<>") && line[a] != symbol))
		return (mini_error(E_INVAL_ID, NULL, EINVAL) * -1);
	if (line[a] && ft_ischarset(line[a], "[{()}]\\;&^%#@*,.:"))
		return (mini_error(E_INVAL_ID, NULL, EINVAL) * -1);
	return (a);
}

int	mini_check_line(char *line)
{
	int		a;

	if (!line)
		return (2);
	a = 0;
	while (line[a])
	{
		if (line[a] == '"' || line[a] == '\'')
			a = mini_loop_quote(line, line[a], a + 1);
		if (a < 0)
			return (1);
		if (mini_check_supported_char(line, a))
			return (1);
		if (line[a] && ft_ischarset(line[a], "|<>"))
			a = mini_check_syntax(line, line[a], a + 1);
		if (a < 0)
			return (1);
		if (line[a])
			a++;
	}
	return (0);
}

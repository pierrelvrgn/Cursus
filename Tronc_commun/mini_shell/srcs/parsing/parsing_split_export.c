/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split_export.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljohnson <ljohnson@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 10:30:33 by ljohnson          #+#    #+#             */
/*   Updated: 2022/06/26 10:04:26 by ljohnson         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	mini_jump_quote(char *str, int i)
{
	char	quote;

	quote = str[i];
	i++;
	while (str[i] && str[i] != quote)
		i++;
	return (i);
}

int	mini_count_words_export(char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			if (str[i] && str[i] != ' ')
				count++;
		}
		else
		{
			if (str[i] && str[i - 1] == ' ' && str[i] != ' ')
				count++;
			if (str[i] && (str[i] == '"' || str[i] == '\''))
				i = mini_jump_quote(str, i);
		}
		if (str[i])
			i++;
	}
	return (count);
}

char	*mini_get_split_part(char *str, int *i)
{
	char	*split_part;
	int		a;
	char	quote;

	*i = skip_space(*i, str);
	a = *i;
	quote = '\0';
	while (str[*i])
	{
		if (str[*i] == '"' || str[*i] == '\'')
		{
			quote = str[*i];
			(*i)++;
			while (str[*i] && str[*i] != quote)
				(*i)++;
		}
		if (str[*i] && str[*i] == ' ')
			break ;
		if (str[*i])
			(*i)++;
	}
	split_part = ft_substr(str, a, *i - a);
	return (un_dblequote(split_part));
}

char	**split_export(char *str)
{
	char	**split;
	int		count;
	int		i;
	int		a;

	count = mini_count_words_export(str);
	split = ft_calloc(count + 1, sizeof(char *));
	if (!split)
		return (NULL);
	split[count] = NULL;
	i = 0;
	a = 0;
	while (a < count)
	{
		split[a] = mini_get_split_part(str, &i);
		if (!split[a])
		{
			mini_error(E_MALLOC, NULL, ENOMEM);
			return (NULL);
		}
		a++;
	}
	return (split);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 08:16:42 by plavergn          #+#    #+#             */
/*   Updated: 2022/06/24 08:17:25 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	mini_check_spaces_heredoc(char *str, int i)
{
	i += 2;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

static char	*remove_heredoc(char *str)
{
	int		i;
	int		a;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	while (str[i])
	{
		if (str[i + 1] && str[i] == '<' && str[i + 1] == '<')
		{
			a = i;
			i = mini_check_spaces_heredoc(str, i);
			tmp1 = ft_substr(str, 0, a);
			tmp2 = ft_substr(str, i, ft_strlen(str));
			free (str);
			str = ft_strfreejoin(tmp1, tmp2);
			i = 0;
		}
		else
			i++;
	}
	return (str);
}

static int	mini_check_spaces_fd_in(char *str, int i)
{
	i++;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
		i++;
	return (i);
}

static char	*remove_fd_in(char *str)
{
	int		i;
	int		a;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	while (str[i])
	{
		if (str[i] == '<')
		{
			a = i;
			i = mini_check_spaces_fd_in(str, i);
			tmp1 = ft_substr(str, 0, a);
			tmp2 = ft_substr(str, i, ft_strlen(str));
			free (str);
			str = ft_strfreejoin(tmp1, tmp2);
			i = 0;
		}
		else
			i++;
	}
	return (str);
}

char	*remove_all(char *str)
{
	str = remove_heredoc(str);
	str = remove_fd_in(str);
	return (str);
}

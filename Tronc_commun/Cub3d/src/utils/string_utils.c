/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:18:23 by plavergn          #+#    #+#             */
/*   Updated: 2022/11/23 09:59:20 by plavergn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen_char(t_cub *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i > 0 && str[i] != '1' && str[i] != '0')
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
			ft_exit(1, "BAD_MAP", data);
		i--;
	}
	if (i == 0)
		ft_exit(1, "BAD_MAP", data);
	return (i + 1);
}

char	*ft_substr(t_cub *data, char *str, char *read, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		str[i] = read[i];
		i++;
	}
	while (i < data->map.sizeline)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:12:47 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/06 11:01:55 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_equal_columns(char *map)
{
	int	columns;
	int	i;
	int	j;

	columns = 0;
	while (map[columns] != '\n')
		++columns;
	i = 0;
	j = 0;
	while (map[i] != '\0')
	{
		if ((map[i] == '\n' && j != columns))
			return (-1);
		else if (map[i] == '\n' && j == columns)
			j = 0;
		else
			j++;
		i++;
	}
	if (j != columns)
		return (-1);
	return (0);
}

int	check_first_last_line(char *map)
{
	int		i;
	char	*last_line;

	i = 0;
	while (map[i] != '\n')
	{
		if (map[i] != '1')
			return (-1);
		i++;
	}
	i = 0;
	last_line = ft_strrchr(map, 'n') + 1;
	while (last_line[i] != '\0')
	{
		if (last_line[i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	get_chr_len(char *s, char c, int len)
{
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

int	check_first_last_columns(char *map)
{
	int	init_len;
	int	end_len;

	init_len = 0;
	end_len = 0;
	while (map[end_len] != '\0')
	{
		end_len = get_chr_len(map, '\n', end_len + 1);
		if (map[init_len] != '1' || map[end_len -1] != '1')
			return (-1);
			init_len = (end_len + 1);
	}
	return (0);
}

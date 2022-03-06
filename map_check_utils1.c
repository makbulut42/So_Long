/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 08:55:14 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/06 11:00:56 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_multiple_players(char *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != '\0')
	{
		if (map[i] == 'P')
			j++;
		i++;
	}
	if (j != 1)
		return (-1);
	return (0);
}

int	check_diff_characters(char *map, char *characters)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (map[i] != '\0')
	{
		j = 0;
		while (characters[j] != '\0')
		{
			if (map[i] == characters[j] || map[i] == '\n')
			{
				k++;
				break ;
			}
			else
				j++;
		}
		i++;
	}
	if ((int)ft_strlen(map) != k)
		return (-1);
	return (0);
}

int	check_missing_characters(char *map, char *characters)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (characters[i] != '\0')
	{
		j = 0;
		while (map[j] != '\0')
		{
			if (characters[i] == map[j])
			{
				k++;
				break ;
			}
			else
				j++;
		}
		i++;
	}
	if ((int)ft_strlen(characters) != k)
		return (-1);
	return (0);
}

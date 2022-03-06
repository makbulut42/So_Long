/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 08:37:07 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/06 11:04:07 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	buffer_update(char **buffer, char **map)
{
	char	*temp;

	temp = ft_strjoin(*map, *buffer);
	free(*map);
	*map = ft_strdup(temp);
	free(temp);
}

int	load_map(char *map_name, char **map)
{
	int		fd;
	int		read_call;
	char	*buffer;

	fd = open(map_name, O_RDONLY);
	*map = ft_calloc(1, 1);
	buffer = malloc(100);
	read_call = read(fd, buffer, 99);
	while (read_call > 0)
	{
		buffer[read_call] = '\0';
		buffer_update(&buffer, map);
		read_call = read(fd, buffer, 99);
	}
	close(fd);
	free (buffer);
	if (fd == -1 || read_call == -1)
		return (-1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 07:53:00 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/06 11:03:04 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(char *map_name, char **map)
{
	if (ft_memcmp(ft_strrchr(map_name, '.'), ".ber", 4) != 0)
		return (handle_extension_error());
	if (load_map(map_name, map) == -1)
		return (handle_bad_file_error());
	if (check_diff_characters(*map, "01CEP") == -1)
		return (handle_bad_characters_error());
	if (check_missing_characters(*map, "01CEP") == -1)
		return (handle_missing_characters_error());
	if (check_multiple_players(*map) == -1)
		return (handle_multiple_players_error());
	if (check_equal_columns(*map) == -1)
		return (handle_not_rectangular_error());
	if (check_first_last_columns(*map) == -1)
		return (handle_not_surrounded_error());
	if (check_first_last_columns(*map) == -1)
		return (handle_not_surrounded_error());
	return (0);
}

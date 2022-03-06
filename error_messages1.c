/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 07:57:50 by makbulut          #+#    #+#             */
/*   Updated: 2022/02/28 11:26:26 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_extension_error(void)
{
	ft_putendl_fd("Error\nBad extension.", 2);
	return (-1);
}

int	handle_bad_file_error(void)
{
	ft_putendl_fd("Error\nBad file.", 2);
	return (-1);
}

int	handle_bad_characters_error(void)
{
	ft_putendl_fd("Error\nBad characters.", 2);
	return (-1);
}

int	handle_missing_characters_error(void)
{
	ft_putendl_fd("Error\nMissing characters.", 2);
	return (-1);
}

int	handle_multiple_players_error(void)
{
	ft_putendl_fd("Error\nMultiple players.", 2);
	return (-1);
}

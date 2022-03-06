/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:16:16 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/06 10:57:15 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_not_rectangular_error(void)
{
	ft_putendl_fd("Error\nWrong number of rectangular.", 2);
	return (-1);
}

int	handle_arguments_error(void)
{
	ft_putendl_fd("Error\nMap is not arguments.", 2);
	return (-1);
}

int	handle_not_surrounded_error(void)
{
	ft_putendl_fd("Error\nMap is not surrounded by walls.", 2);
	return (-1);
}

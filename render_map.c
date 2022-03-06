/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 00:44:51 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/06 11:12:22 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_data *so_long)
{
	if (*so_long->map == '1')
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
		so_long->create_wall, so_long->x, so_long->y);
	else if (*so_long->map == 'P')
	{
		if (so_long->curr_pos == 'R')
			mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->create_gaci_r, so_long->x, so_long->y);
		else if (so_long->curr_pos == 'L')
			mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->create_gaci_l, so_long->x, so_long->y);
		else if (so_long->curr_pos == 'U')
			mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->create_gaci_u, so_long->x, so_long->y);
		else if (so_long->curr_pos == 'D')
			mlx_put_image_to_window(so_long->mlx, so_long->win, \
			so_long->create_gaci_d, so_long->x, so_long->y);
	}
	else if (*so_long->map == 'C')
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
		so_long->create_point, so_long->x, so_long->y);
	else if (*so_long->map == 'E')
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
		so_long->create_exit, so_long->x, so_long->y);
	so_long->x += 60;
}

void	render_map(t_data *so_long)
{	
	char	*pos;

	pos = so_long->map;
	so_long->x = 0;
	so_long->y = 0;
	while (*so_long->map)
	{
		if (*so_long->map == '\n')
		{
			so_long->x = 0;
			so_long->y += 60;
		}
		else
			put_image(so_long);
		so_long->map++;
	}
	so_long->map = pos;
}

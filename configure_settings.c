/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_settings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:44:02 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/06 10:56:55 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	crate_img(t_data *so_long)
{
	so_long->create_wall = mlx_xpm_file_to_image(so_long->mlx, \
	"./xpm/wall.xpm", &so_long->wall.width, &so_long->wall.height);
	so_long->create_gaci_d = mlx_xpm_file_to_image(so_long->mlx, \
	"./xpm/gaci.xpm", &so_long->player.width, &so_long->player.height);
	so_long->create_gaci_u = mlx_xpm_file_to_image(so_long->mlx, \
	"./xpm/w_gaci.xpm", &so_long->exit.width, &so_long->exit.height);
	so_long->create_gaci_r = mlx_xpm_file_to_image(so_long->mlx, \
	"./xpm/d_gaci.xpm", &so_long->exit.width, &so_long->exit.height);
	so_long->create_gaci_l = mlx_xpm_file_to_image(so_long->mlx, \
	"./xpm/a_gaci.xpm", &so_long->exit.width, &so_long->exit.height);
	so_long->create_point = mlx_xpm_file_to_image(so_long->mlx, \
	"./xpm/character.xpm", &so_long->empty.width, &so_long->empty.height);
	so_long->create_exit = mlx_xpm_file_to_image(so_long->mlx, \
	"./xpm/exit.xpm", &so_long->exit.width, &so_long->exit.height);
}

void	configure_settings(t_data *so_long)
{
	int	i;

	i = 0;
	crate_img(so_long);
	while (so_long->map[i] != '\n')
	{
		so_long->row_len++;
		i++;
	}
	i = 1;
	while (so_long->map[i])
	{
		if (so_long->map[i] == '\n')
			so_long->colom_len++;
		i++;
	}
	so_long->win = mlx_new_window(so_long->mlx, (so_long->row_len) \
	* 60, (so_long->colom_len) * 60, "GAME WINDOW!");
	so_long->curr_pos = 'D';
	render_map(so_long);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:50:15 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/06 14:20:46 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_count(t_data *so_long)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	so_long->collect_pos = 0;
	so_long->player_count = 0;
	while (so_long->map[i])
	{
		if (so_long->map[i] == 'P')
		{
			so_long->player_count = i;
		}
		else if (so_long->map[i] == 'C')
		{
			so_long->collect_pos = ++j;
		}
		i++;
	}
}

int	close_screen(t_data *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->win);
	free(so_long->map);
	ft_putendl_fd("Window is Closed!", 1);
	exit(1);
}

int	main(int ac, char **av)
{
	t_data	so_long;
	int		i;

	i = 0;
	if (ac == 2)
	{
		if (map_check(av[1], &so_long.map) == -1)
		{
			free (so_long.map);
			return (-1);
		}
		so_long.mlx = mlx_init();
		player_count(&so_long);
		configure_settings(&so_long);
		key_input(&so_long);
		mlx_loop(so_long.mlx);
	}
	else
		handle_arguments_error();
	return (0);
}

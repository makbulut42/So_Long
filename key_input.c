/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:41:47 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/06 14:21:28 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_action(t_data *data, int x)
{
	if (data->map[x] != '1')
	{
		if (data->map[x] == 'C')
		{
			data->collect_pos--;
			data->map[x] = '0';
		}
		if (data->map[x] == 'E' && data->collect_pos < 1)
		{
			printf("Moves: %d\nYou Winner!\n", ++(data->move_count));
			free(data->map);
			exit(1);
		}
		if (data->map[x] == 'E')
		{
			return (0);
		}
		printf("Moves: %d\n", ++(data->move_count));
		return (1);
	}
	return (0);
}

void	right_left(int keycode, t_data *so_long)
{
	if (keycode == D_KEY)
	{
		if (check_action(so_long, ((so_long->player_count) + 1)))
		{
			so_long->map[so_long->player_count] = '0';
			so_long->player_count += 1;
			so_long->map[so_long->player_count] = 'P';
			so_long->curr_pos = 'R';
		}
	}
	else if (keycode == A_KEY)
	{
		if (check_action(so_long, ((so_long->player_count) - 1)))
		{
			so_long->map[so_long->player_count] = '0';
			so_long->player_count -= 1;
			so_long->map[so_long->player_count] = 'P';
			so_long->curr_pos = 'L';
		}
	}
}

void	up_down(int keycode, t_data *so_long)
{
	if (keycode == W_KEY)
	{	
		if (check_action(so_long, \
		((so_long->player_count) - (so_long->row_len + 1))))
		{
			so_long->map[so_long->player_count] = '0';
			so_long->player_count -= (so_long->row_len + 1);
			so_long->map[so_long->player_count] = 'P';
			so_long->curr_pos = 'U';
		}
	}
	else if (keycode == S_KEY)
	{
		if (check_action(so_long, \
		((so_long->player_count) + (so_long->row_len + 1))))
		{
			so_long->map[so_long->player_count] = '0';
			so_long->player_count += (so_long->row_len + 1);
			so_long->map[so_long->player_count] = 'P';
			so_long->curr_pos = 'D';
		}
	}
}

int	key_hook(int keycode, t_data *so_long)
{
	if (keycode == ESC_KEY)
	{
		ft_putendl_fd("Game Exited", 1);
		free(so_long->map);
		exit(1);
	}
	else if (keycode == D_KEY || keycode == A_KEY)
		right_left(keycode, so_long);
	else if (keycode == W_KEY || keycode == S_KEY)
		up_down(keycode, so_long);
	mlx_clear_window(so_long->mlx, so_long->win);
	render_map(so_long);
	return (0);
}

void	key_input(t_data *so_long)
{
	mlx_hook(so_long->win, 2, 1L << 0, key_hook, so_long);
	mlx_hook(so_long->win, 17, 1L << 17, close_screen, so_long);
}

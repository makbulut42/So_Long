/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:50:54 by makbulut          #+#    #+#             */
/*   Updated: 2022/03/06 14:10:15 by makbulut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./mlx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

enum
{
	ESC_KEY = 53,
	W_KEY = 13,
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2
};

typedef struct s_assets
{
	void	*img;
	int		width;
	int		height;
}	t_assets;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*create_wall;
	void		*create_gaci;
	void		*create_gaci_u;
	void		*create_gaci_d;
	void		*create_gaci_r;
	void		*create_gaci_l;
	void		*create_point;
	void		*create_exit;
	char		*map;
	char		*map_img;
	char		curr_pos;
	int			colom_len;
	int			row_len;
	int			x;
	int			y;
	int			collect_pos;
	int			player_count;
	int			move_count;
	t_assets	collect;
	t_assets	empty;
	t_assets	exit;
	t_assets	player;
	t_assets	wall;
}				t_data;

int		handle_extension_error(void);
int		handle_bad_file_error(void);
int		map_check(char *map_name, char **map);
int		check_diff_characters(char *map, char *characters);
int		handle_bad_characters_error(void);
int		check_missing_characters(char *map, char *characters);
int		handle_missing_characters_error(void);
int		handle_multiple_players_error(void);
int		check_equal_columns(char *map);
int		load_map(char *map_name, char **map);
int		handle_not_rectangular_error(void);
int		check_first_last_line(char *map);
int		handle_not_surrounded_error(void);
int		check_first_last_columns(char *map);
int		check_multiple_players(char *map);
int		handle_arguments_error(void);
int		keyboard_hook(int keycode, t_data so_long);
int		key_hook(int keycode, t_data *vars);
void	init_map(t_data so_long);
void	configure_settings(t_data *so_long);
void	render_map(t_data *so_long);
void	key_input(t_data *so_long);
int		close_screen(t_data *so_long);
void	end_game(t_data *so_long);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 10:27:34 by mpons             #+#    #+#             */
/*   Updated: 2021/12/31 16:24:19 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../inc/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct s_map
{
	char	**map;
	char	*name;
	int		fd;
	int		len_line;
	int		q_line;
	int		end_line;
	int		p_chk;
	int		e_chk;
	int		c_chk;
}	t_map;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}	t_mlx;

typedef struct s_game
{
	t_mlx	mlx;
	t_map	*m;
	int		win_width;
	int		win_height;
	int		img_width;
	int		img_height;
	int		move_count;
	int		x;
	int		y;
	void	*img_c;
	void	*img_1;
	void	*img_0;
	void	*img_e;
	void	*img_u;
	void	*img_d;
	void	*img_l;
	void	*img_r;
}	t_game;

void	vide_error(void);
void	wall_error(void);
void	wall_error2(void);
void	line_len_error(void);
void	ft_read_map(t_map *m);
int		check_wall(char *l);
void	check_map(t_map *m);
void	init_game(t_map *m, t_game *g);
void	print_map(t_map *m, t_game *g);
int		key_hook(int keycode, t_game *g);
int		exit_hook(t_game *g);
void	move_up(t_map *m, t_game *g);
void	move_down(t_map *m, t_game *g);
void	move_left(t_map *m, t_game *g);
void	move_right(t_map *m, t_game *g);

#endif

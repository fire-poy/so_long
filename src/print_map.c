/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:07:41 by mpons             #+#    #+#             */
/*   Updated: 2021/12/31 16:20:10 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

void	init_game(t_map *m, t_game *g)
{
	g->move_count = 0;
	g->m = m;
	g->mlx.ptr = mlx_init();
	g->img_1 = mlx_xpm_file_to_image(g->mlx.ptr, "./img/arbol64.xpm",
			&g->img_width, &g->img_height);
	g->img_0 = mlx_xpm_file_to_image(g->mlx.ptr, "./img/fondo64.xpm",
			&g->img_width, &g->img_height);
	g->img_c = mlx_xpm_file_to_image(g->mlx.ptr, "./img/llave64.xpm",
			&g->img_width, &g->img_height);
	g->img_e = mlx_xpm_file_to_image(g->mlx.ptr, "./img/carpa64.xpm",
			&g->img_width, &g->img_height);
	g->img_u = mlx_xpm_file_to_image(g->mlx.ptr, "./img/up64.xpm",
			&g->img_width, &g->img_height);
	g->img_d = mlx_xpm_file_to_image(g->mlx.ptr, "./img/down64.xpm",
			&g->img_width, &g->img_height);
	g->img_l = mlx_xpm_file_to_image(g->mlx.ptr, "./img/left64.xpm",
			&g->img_width, &g->img_height);
	g->img_r = mlx_xpm_file_to_image(g->mlx.ptr, "./img/right64.xpm",
			&g->img_width, &g->img_height);
	g->win_width = m->len_line * g->img_width;
	g->win_height = m->q_line * g->img_height;
	g->mlx.win = mlx_new_window(g->mlx.ptr,
			g->win_width, g->win_height, m->name);
}

void	put_image(char c, t_game *g, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(g->mlx.ptr, g->mlx.win, g->img_1, x, y);
	if (c == '0')
		mlx_put_image_to_window(g->mlx.ptr, g->mlx.win, g->img_0, x, y);
	if (c == 'C')
		mlx_put_image_to_window(g->mlx.ptr, g->mlx.win, g->img_c, x, y);
	if (c == 'P')
		mlx_put_image_to_window(g->mlx.ptr, g->mlx.win, g->img_d, x, y);
	if (c == 'E')
		mlx_put_image_to_window(g->mlx.ptr, g->mlx.win, g->img_e, x, y);
}

void	print_map(t_map *m, t_game *g)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (m->map[i])
	{
		j = 0;
		x = 0;
		while (m->map[i][j])
		{
			put_image(m->map[i][j], g, x, y);
			x += g->img_width;
			j++;
		}
		y += g->img_height;
		i++;
	}
}

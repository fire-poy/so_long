/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:24:31 by mpons             #+#    #+#             */
/*   Updated: 2021/12/31 14:39:10 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

char	*ft_tabchr(char **t, char c, t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (t[i][j])
	{
		while (t[i][j])
		{
			if (t[i][j] == c)
			{
				g->x = j;
				g->y = i;
				return (t[i] + j);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

void	move_up(t_map *m, t_game *g)
{
	ft_tabchr(m->map, 'P', g);
	g->y--;
	if (m->map[g->y][g->x] != '1')
	{
		if (m->map[g->y][g->x] == 'E')
		{
			if (m->c_chk == 0)
				exit_hook(g);
			else
				return ;
		}
		if (m->map[g->y][g->x] == 'C')
			m->c_chk--;
		m->map[g->y][g->x] = 'P';
		mlx_put_image_to_window(g->mlx.ptr, g->mlx.win,
			g->img_u, g->x * g->img_width, g->y * g->img_height);
		m->map[g->y + 1][g->x] = '0';
		mlx_put_image_to_window(g->mlx.ptr, g->mlx.win,
			g->img_0, g->x * g->img_width, (g->y + 1) * g->img_height);
		g->move_count++;
		ft_putnbr_fd(g->move_count, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_down(t_map *m, t_game *g)
{
	ft_tabchr(m->map, 'P', g);
	g->y++;
	if (m->map[g->y][g->x] != '1')
	{
		if (m->map[g->y][g->x] == 'E')
		{
			if (m->c_chk == 0)
				exit_hook(g);
			else
				return ;
		}
		if (m->map[g->y][g->x] == 'C')
			m->c_chk--;
		m->map[g->y][g->x] = 'P';
		mlx_put_image_to_window(g->mlx.ptr, g->mlx.win,
			g->img_d, g->x * g->img_width, g->y * g->img_height);
		m->map[g->y - 1][g->x] = '0';
		mlx_put_image_to_window(g->mlx.ptr, g->mlx.win,
			g->img_0, g->x * g->img_width, (g->y - 1) * g->img_height);
		g->move_count++;
		ft_putnbr_fd(g->move_count, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_left(t_map *m, t_game *g)
{
	ft_tabchr(m->map, 'P', g);
	g->x--;
	if (m->map[g->y][g->x] != '1')
	{
		if (m->map[g->y][g->x] == 'E')
		{
			if (m->c_chk == 0)
				exit_hook(g);
			else
				return ;
		}
		if (m->map[g->y][g->x] == 'C')
			m->c_chk--;
		m->map[g->y][g->x] = 'P';
		mlx_put_image_to_window(g->mlx.ptr, g->mlx.win,
			g->img_l, g->x * g->img_width, g->y * g->img_height);
		m->map[g->y][g->x + 1] = '0';
		mlx_put_image_to_window(g->mlx.ptr, g->mlx.win,
			g->img_0, (g->x + 1) * g->img_width, g->y * g->img_height);
		g->move_count++;
		ft_putnbr_fd(g->move_count, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	move_right(t_map *m, t_game *g)
{
	ft_tabchr(m->map, 'P', g);
	g->x++;
	if (m->map[g->y][g->x] != '1')
	{
		if (m->map[g->y][g->x] == 'E')
		{
			if (m->c_chk == 0)
				exit_hook(g);
			else
				return ;
		}
		if (m->map[g->y][g->x] == 'C')
			m->c_chk--;
		m->map[g->y][g->x] = 'P';
		mlx_put_image_to_window(g->mlx.ptr, g->mlx.win,
			g->img_r, g->x * g->img_width, g->y * g->img_height);
		m->map[g->y][g->x - 1] = '0';
		mlx_put_image_to_window(g->mlx.ptr, g->mlx.win,
			g->img_0, (g->x - 1) * g->img_width, g->y * g->img_height);
		g->move_count++;
		ft_putnbr_fd(g->move_count, 1);
		ft_putchar_fd('\n', 1);
	}
}

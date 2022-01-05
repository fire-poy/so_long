/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:07:51 by mpons             #+#    #+#             */
/*   Updated: 2021/12/31 16:08:54 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

int	exit_hook(t_game *g)
{
	free(g->m->map);
	exit(0);
	return (1);
}

int	key_hook(int keycode, t_game *g)
{
	if (keycode == 53)
		exit_hook(g);
	if (keycode == 13)
		move_up(g->m, g);
	if (keycode == 1)
		move_down(g->m, g);
	if (keycode == 0)
		move_left(g->m, g);
	if (keycode == 2)
		move_right(g->m, g);
	return (1);
}

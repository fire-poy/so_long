/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:59:37 by mpons             #+#    #+#             */
/*   Updated: 2021/12/31 16:28:24 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

void	check_wall_fin(t_map *m)
{
	int	z;
	int	j;

	z = m->q_line - 1;
	j = 0;
	while (m->map[z][j])
	{
		if (m->map[z][j] != '1')
		{
			free(m->map);
			wall_error();
		}
		j++;
	}
}

void	check_char_and_count(char c, t_map *m)
{
	if (c != 'P' && c != 'E' && c != 'C' && c != '1' && c != '0')
	{
		ft_putendl_fd("Error\nWrong char", 2);
		free(m->map);
		exit (1);
	}
	if (c == 'P')
		m->p_chk++;
	if (c == 'E')
		m->e_chk++;
	if (c == 'C')
		m->c_chk++;
}

void	check_errors(t_map *m)
{
	if (m->p_chk != 1 || m->e_chk == 0 || m->c_chk == 0
		|| m->q_line == m->len_line)
	{
		ft_putendl_fd("Error", 2);
		if (m->p_chk == 0)
			ft_putendl_fd("No Player", 2);
		if (m->p_chk > 1)
			ft_putendl_fd("More than 1 Player", 2);
		if (m->e_chk == 0)
			ft_putendl_fd("No Exit", 2);
		if (m->c_chk == 0)
			ft_putendl_fd("No colectibles", 2);
		if (m->q_line == m->len_line)
			ft_putendl_fd("Squarre map", 2);
		free(m->map);
		exit (1);
	}
}

void	check_map(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->map[i])
	{
		while (m->map[i][j])
		{
			check_char_and_count(m->map[i][j], m);
			j++;
		}
		i++;
		j = 0;
	}
	check_errors(m);
	check_wall_fin(m);
}

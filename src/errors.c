/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:07:48 by mpons             #+#    #+#             */
/*   Updated: 2021/12/31 16:45:27 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

int	check_wall(char *l)
{
	int	i;

	i = 0;
	if (!l)
		vide_error();
	while (l[i] && l[i] != '\n')
	{
		if (l[i] != '1')
		{
			free(l);
			wall_error();
		}
		i++;
	}
	return (i);
}

void	wall_error(void)
{
	ft_putendl_fd("Error\nexternal wall is not closed", 2);
	exit (1);
}

void	wall_error2(void)
{
	ft_putendl_fd("Error\nmidwall is not closed", 2);
	exit (1);
}

void	line_len_error(void)
{
	ft_putendl_fd("Error\ndiferents len line ", 2);
	exit (1);
}

void	vide_error(void)
{
	ft_putendl_fd("Error\nempty map", 2);
	exit (1);
}

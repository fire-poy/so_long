/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:17:37 by mpons             #+#    #+#             */
/*   Updated: 2022/01/03 20:36:59 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

void	fd_error(void)
{
	perror("Error\n");
	exit (1);
}

void	check_wall(char *l)
{
	int	i;

	i = 0;
	if (!l)
		print_error_exit("Error\nempty map");
	while (l[i] && l[i] != '\n')
	{
		if (l[i] != '1')
		{
			free(l);
			print_error_exit("Error\nExternal wall is not closed");
		}
		i++;
	}
}

void	max_taille(t_map *m)
{
	if (m->q_line > 21 || m->len_line > 40)
	{
		free(m->map);
		print_error_exit("Error\nExceeded map size");
	}
}

void	ft_read_map(t_map *m)
{
	char	*line;
	char	all_char[862];

	m->fd = open(m->name, O_RDONLY);
	if (m->fd == -1)
		fd_error();
	line = get_next_line(m->fd);
	check_wall(line);
	m->len_line = (int)ft_strlen(line) - 1;
	while (line)
	{
		if (line[0] != '1' || line[m->len_line - 1] != '1')
			print_error_exit("Error\nmidwall is not closed");
		ft_strcat(all_char, line);
		m->q_line++;
		free(line);
		line = get_next_line(m->fd);
		if (line && (int)ft_strlen(line) - 1 != m->len_line)
			print_error_exit("Error\ndiferents len line");
	}
	m->map = ft_split(all_char, '\n');
	m->fd = close(m->fd);
	max_taille(m);
}	

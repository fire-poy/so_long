/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 11:17:37 by mpons             #+#    #+#             */
/*   Updated: 2021/12/31 16:48:29 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

void	fd_error(void)
{
	perror("Error\n");
	exit (1);
}

void	max_taille(t_map *m)
{
	if (m->q_line > 21 || m->len_line > 40)
	{
		ft_putendl_fd("Error\nExceeded map size", 2);
		free(m->map);
		exit (1);
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
	m->len_line = check_wall(line);
	m->end_line = m->len_line - 1;
	while (line)
	{
		if (line[0] != '1' || line[m->end_line] != '1')
			wall_error2();
		ft_strcat(all_char, line);
		m->q_line++;
		free(line);
		line = get_next_line(m->fd);
		if (line && (int)ft_strlen(line) - 1 != m->len_line)
			line_len_error();
	}
	m->map = ft_split(all_char, '\n');
	m->fd = close(m->fd);
	max_taille(m);
}	
//me aparecen problemas de memoria cuando all_char[9217],
//hay como residuos de char non imprimables que quedan en el primer string 

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:05:18 by mpons             #+#    #+#             */
/*   Updated: 2021/12/31 16:13:58 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

void	check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putendl_fd("Error\nInvalid number of argument", 2);
		exit (1);
	}
	if (ft_strlen(av[1]) < 4 || (!ft_strchr(av[1], '.')))
	{
		ft_putendl_fd("Error\nInvalid argument", 2);
		exit (1);
	}
	if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0)
	{
		ft_putendl_fd("Error\nInvalid map type", 2);
		exit (1);
	}
}

void	init_struct(t_map *map, char *map_name)
{
	map->len_line = 0;
	map->q_line = 0;
	map->end_line = 0;
	map->p_chk = 0;
	map->e_chk = 0;
	map->c_chk = 0;
	map->name = map_name;
}

int	main(int ac, char **av)
{
	t_game	game;
	t_map	map;

	check_arg(ac, av);
	init_struct(&map, av[1]);
	ft_read_map(&map);
	check_map(&map);
	init_game(&map, &game);
	print_map(&map, &game);
	mlx_key_hook(game.mlx.win, key_hook, &game);
	mlx_hook(game.mlx.win, 17, 0, exit_hook, &game);
	mlx_loop(game.mlx.ptr);
	free(map.map);
	return (0);
}

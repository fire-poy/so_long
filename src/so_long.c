/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpons <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:05:18 by mpons             #+#    #+#             */
/*   Updated: 2022/01/03 20:38:49 by mpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/so_long.h"

void	check_arg(int ac, char **av)
{
	if (ac != 2)
		print_error_exit("Error\nInvalid number of argument");
	if (ft_strlen(av[1]) < 4 || (!ft_strchr(av[1], '.')))
		print_error_exit("Invalid argument");
	if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0)
		print_error_exit("Error\nInvalid map type");
}

void	init_struct(t_map *map, char *map_name)
{
	map->len_line = 0;
	map->q_line = 0;
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

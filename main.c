/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:44:10 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/22 18:34:42 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"


static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || check_extension(argv) == 1)
		ft_error("Invalid arguments");
	get_map(&game, argv[1]);
	check_elements(&game);
	ft_printmap(game.map.map);
	game.mlx = mlx_init(game.map.width * 64, game.map.length * 64, "So_long", true);
	if (!game.mlx)
		ft_error("Mlx init error");
	mlx_loop_hook(game.mlx, ft_hook, game.mlx);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	ft_printf("---------------\n");
	ft_printf("------WIN------\n");
	ft_printf("---------------\n");
	ft_freegame(&game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:44:10 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/23 19:17:56 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	// printear nº de movimientos
		//nº de veces que se pulsa una tecla de moverse W,A,S,D
	ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int	main(int argc, char **argv)
{
	t_game		game;
	mlx_image_t	*img;

	if (argc != 2 || check_extension(argv) == 1)
		ft_error("Invalid arguments");
	get_map(&game, argv[1]);
	check_elements(&game);
	ft_printmap(game.map.map);


	game.images.walls = mlx_load_png("images/rock01.png");
	if (!game.images.walls)
	{
		ft_freegame(&game);
		ft_error("load img error");
	}


	game.mlx = mlx_init(game.map.width * 64, game.map.length * 64, "So_long", true);
	if (!game.mlx)
	{
		ft_freegame(&game);
		ft_error("Mlx init error");
	}

	img = mlx_new_image(game.mlx, game.map.width * 64, game.map.length * 64);
	if (!img)
	{
		ft_freegame(&game);
		ft_error("load img error");
	}
	
	int y;
	int x;
	y = 0;
	while (y < game.map.length)
    {
		x = 0;
        while (x < game.map.width)
        {
            mlx_image_to_window(game.mlx, img, x, y);
			x += 64;
        }
		y += 64;
    }
	mlx_image_to_window(game.mlx, img, 0, 0);

	mlx_loop_hook(game.mlx, ft_hook, game.mlx);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	ft_printf("---------------\n");
	ft_printf("------WIN------\n");
	ft_printf("---------------\n");
	ft_freegame(&game);
	return (0);
}

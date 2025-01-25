/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:44:10 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/23 20:37:33 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

/* static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	(void)mlx;
	// printear nº de movimientos
		//nº de veces que se pulsa una tecla de moverse W,A,S,D
	//ft_printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
} */
void	ft_load_png(t_txture *txture, t_game *game)
{
	txture->coins = mlx_load_png("sprites/coin01.png");
	txture->exit = mlx_load_png("sprites/exit.png");
	if (!txture->coins || !txture->exit)
	{
		ft_freegame(game);
		ft_error("load img error1");
	}
	txture->floor = mlx_load_png("sprites/floor01.png");
	txture->player = mlx_load_png("sprites/player_down01.png");
	if (!txture->floor || !txture->player)
	{
		ft_freegame(game);
		ft_error("load img error2");
	}
	txture->walls = mlx_load_png("sprites/wall03.png");
	if (!txture->walls)
	{
		ft_freegame(game);
		ft_error("load img error3");
	}
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2 || check_extension(argv) == 1)
		ft_error("Invalid arguments");
	get_map(&game, argv[1]);
	check_elements(&game);
	ft_printmap(game.map.map);

	ft_load_png(&game.txture, &game);

	ft_printf("WIDTH: %d | HEIGHT: %d\n", game.map.width, game.map.length);
	game.mlx = mlx_init(game.map.width * 64, game.map.length * 64, "So_long", false);
	if (!game.mlx)
	{
		ft_freegame(&game);
		ft_error("Mlx init error");
	}

	game.images.walls = mlx_texture_to_image(game.mlx, game.txture.walls);
	//img = mlx_new_image(game.mlx, game.map.width * 64, game.map.length * 64);
/* 	if (!img)
	{
		ft_freegame(&game);
		ft_error("load img error");
	}
	 */
	int y;
	int x;
	y = 0;
	while (y < game.map.length)
    {
		x = 0;
        while (x < game.map.width)
        {
            mlx_image_to_window(game.mlx, game.images.walls, x * 64, y * 64);
			x++;
        }
		y++;
    }
	//mlx_image_to_window(game.mlx, img, 0, 0);

	//mlx_loop_hook(game.mlx, ft_hook, game.mlx);
	//mlx_key_hook(game.mlx,);
	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	ft_printf("---------------\n");
	ft_printf("------WIN------\n");
	ft_printf("---------------\n");
	ft_freegame(&game);
	return (0);
}

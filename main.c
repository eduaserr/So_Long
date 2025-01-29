/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:44:10 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/29 18:10:55 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

/*static void ft_hook(void* param)
{
	(void)param;
	// printear nº de movimientos
		//nº de veces que se pulsa una tecla de moverse W,A,S,D
	//mlx_image_to_window();
	ft_printf("hOLA");
} */

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2 || check_extension(argv) == 1)
		ft_error("Invalid arguments");
	get_map(&game, argv[1]);
	check_elements(&game);
	process_images(&game, &game.images, &game.txture);
	ft_printmap(game.map.map);
	ft_printf("WIDTH: %d | HEIGHT: %d\n", game.map.width, game.map.length);
	//mlx_loop_hook(game.mlx, ft_hook, game.mlx);
	
	mlx_key_hook(game.mlx, &ft_key_hook, &game);
	
	mlx_loop(game.mlx);
	ft_printf("---------------\n");
	ft_printf("------WIN------\n");
	ft_printf("---------------\n");
	ft_freegame(&game);
	return (0);
}

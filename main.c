/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:44:10 by eduaserr          #+#    #+#             */
/*   Updated: 2025/02/12 17:33:35 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2 || check_extension(argv) == 1)
		ft_error("Invalid arguments");
	get_map(&game, argv[1]);
	check_elements(&game);
	process_images(&game, game.images, game.txture);
	mlx_key_hook(game.mlx, &ft_key_hook, &game);
	mlx_loop(game.mlx);
	ft_freegame(&game);
	mlx_terminate(game.mlx);
	ft_printf("Game closed . . . ❌\n");
	return (0);
}

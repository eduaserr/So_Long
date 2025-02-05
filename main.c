/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:44:10 by eduaserr          #+#    #+#             */
/*   Updated: 2025/02/05 04:47:30 by eduaserr         ###   ########.fr       */
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
	process_images(&game, game.images, game.txture);
	ft_printmap(game.map.map);
	ft_printf("WIDTH: %d | HEIGHT: %d\n", game.map.width, game.map.length);
	//mlx_loop_hook(game.mlx, ft_hook, game.mlx);
	
	mlx_key_hook(game.mlx, &ft_key_hook, &game);
	
	mlx_loop(game.mlx);
	ft_freegame(&game);
	mlx_terminate(game.mlx);
	return (0);
}

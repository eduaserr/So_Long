/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:44:10 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/25 20:07:43 by eduaserr         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2 || check_extension(argv) == 1)
		ft_error("Invalid arguments");
	get_map(&game, argv[1]);
	check_elements(&game);

	process_images(&game, &game.images, &game.txture);
	//mlx_delete_image();

	ft_printmap(game.map.map);
	ft_printf("WIDTH: %d | HEIGHT: %d\n", game.map.width, game.map.length);

// función para poner una imagen en la ventana
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
	//mlx_image_to_window(game.mlx, game.images.walls, 0, 0);

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

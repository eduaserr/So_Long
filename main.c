/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:44:10 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/27 03:27:48 by eduaserr         ###   ########.fr       */
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

void	ft_key_hook(mlx_key_data_t key, void *param)
{
	t_game	*game;

	game = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
	}
	/*
	if (key.key == MLX_KEY_W && key.action == MLX_PRESS)
		move_player();
	if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
		move_player();
	if (key.key == MLX_KEY_S && key.action == MLX_PRESS)
		move_player();
	if (key.key == MLX_KEY_D && key.action == MLX_PRESS)
		move_player();
	*/
}

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
	mlx_terminate(game.mlx);
	ft_printf("---------------\n");
	ft_printf("------WIN------\n");
	ft_printf("---------------\n");
	ft_freegame(&game);
	return (0);
}

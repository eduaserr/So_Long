/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:44:10 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/27 22:05:28 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

/* static void ft_hook(void* param)
{
	(void)param;
	// printear nº de movimientos
		//nº de veces que se pulsa una tecla de moverse W,A,S,D
	//refresh_frames ,, frame rate
	//mlx_image_to_window();
} */
/*void	move_player(t_game *game, char move)
{
	char pos;

	pos = game->map.map[game->map.player_pos.y][game->map.player_pos.x];
	if (pos == move)
	{
		mlx_image_to_window(game->mlx, game->images.player, game->map.player_pos.x * 64, (game->map.player_pos.y + 1) * 64);
	}
}*/

void	move_player(t_game *game, char move)
{
	int	x;
	int	y;

	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
	(void)move;

	if (move == 'W')
		mlx_image_to_window(game->mlx, game->images.player, x * 64, (y - 1) * 64);
	if (move == 'A')
		mlx_image_to_window(game->mlx, game->images.player, (x - 1) * 64, y * 64);
	if (move == 'S')
		mlx_image_to_window(game->mlx, game->images.player, x * 64, (y + 1) * 64);
	if (move == 'D')
		mlx_image_to_window(game->mlx, game->images.player, (x + 1) * 64, y * 64);
	mlx_image_to_window(game->mlx, game->images.floor, x * 64, y * 64);
}

void	ft_key_hook(mlx_key_data_t key, void *param)
{
	t_game	*game;

	game = param;
	if ((key.key == MLX_KEY_ESCAPE || key.key == MLX_KEY_Q)
		&& key.action == MLX_PRESS)
	{
		mlx_close_window(game->mlx);
		ft_freegame(game);
		ft_printf("Exit . . .❌🔌\n");
		exit(EXIT_SUCCESS);
	}
	if (key.key == MLX_KEY_W && key.action == MLX_PRESS)
		move_player(game, 'W');
	if (key.key == MLX_KEY_A && key.action == MLX_PRESS)
		move_player(game, 'A');
	if (key.key == MLX_KEY_S && key.action == MLX_PRESS)
		move_player(game, 'S');
	if (key.key == MLX_KEY_D && key.action == MLX_PRESS)
		move_player(game, 'D');
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
	ft_printf("---------------\n");
	ft_printf("------WIN------\n");
	ft_printf("---------------\n");
	ft_freegame(&game);
	return (0);
}

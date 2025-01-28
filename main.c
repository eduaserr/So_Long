/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:44:10 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/28 21:22:02 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

/* static void ft_hook(void* param)
{
	(void)param;
	// printear nº de movimientos
		//nº de veces que se pulsa una tecla de moverse W,A,S,D
	//mlx_image_to_window();
} */

/*void	move_player(t_game *game, char move)
{
	int	x;
	int	y;

	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
	mlx_image_to_window(game->mlx, game->images.floor, x * 64, y * 64);
	if (move == 'W' && (--y < 0 && y < game->map.length))
	{
		mlx_image_to_window(game->mlx, game->images.player.playerup, x * 64, y * 64);
	}
	else if (move == 'A' && (--x > 0 && x < game->map.width))
	{
		mlx_image_to_window(game->mlx, game->images.player.playerleft, x * 64, y * 64);
	}
	else if (move == 'S' && (++y > 0 && y < game->map.length))
	{
		mlx_image_to_window(game->mlx, game->images.player.playerdown, x * 64, y * 64);
	}
	else if (move == 'D' && (++x > 0 && x < game->map.width))
	{
		mlx_image_to_window(game->mlx, game->images.player.playerright, x * 64, y * 64);
	}
	game->map.player_pos.x = x;
	game->map.player_pos.y = y;
}*/

void	move_player(t_game *game, char move)
{
	int	x;
	int	y;

	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
	mlx_image_to_window(game->mlx, game->images.floor, x * 64, y * 64);
	if (move == 'W')
	{
		y--;
		mlx_image_to_window(game->mlx, game->images.player.playerup, x * 64, y * 64);
	}
	if (move == 'A')
	{
		x--;
		mlx_image_to_window(game->mlx, game->images.player.playerleft, x * 64, y * 64);
	}
	if (move == 'S')
	{
		y++;
		mlx_image_to_window(game->mlx, game->images.player.playerdown, x * 64, y * 64);
	}
	if (move == 'D')
	{
		x++;
		mlx_image_to_window(game->mlx, game->images.player.playerright, x * 64, y * 64);
	}
	game->map.player_pos.x = x;
	game->map.player_pos.y = y;
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
		ft_printf("Exit game . . .❌🔌\n");
		exit(EXIT_SUCCESS);
	}
	if ((key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
		&& key.action == MLX_PRESS)
		move_player(game, 'W');
	if ((key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
		&& key.action == MLX_PRESS)
		move_player(game, 'A');
	if ((key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		&& key.action == MLX_PRESS)
		move_player(game, 'S');
	if ((key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
		&& key.action == MLX_PRESS)
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

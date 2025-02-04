/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_keyhook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:52:31 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/29 16:53:13 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	update_pos(t_game *game, char move, int x, int y)
{
	mlx_image_to_window(game->mlx, game->images->floor, x * 64, y * 64);
	if (move == 'W')
	{
		mlx_image_to_window(game->mlx, game->images->player->playerup,
			x * 64, --y * 64);
	}
	else if (move == 'A')
	{
		mlx_image_to_window(game->mlx, game->images->player->playerleft,
			--x * 64, y * 64);
	}
	else if (move == 'S')
	{
		mlx_image_to_window(game->mlx, game->images->player->playerdown,
			x * 64, ++y * 64);
	}
	else if (move == 'D')
	{
		mlx_image_to_window(game->mlx, game->images->player->playerright,
			++x * 64, y * 64);
	}
	game->map.player_pos.x = x;
	game->map.player_pos.y = y;
}

int	check_walls(t_game *game, char move, int x , int y)
{
	if (move == 'W')
	{
		if (game->map.map[y - 1][x] == '1'
			|| game->map.map[y - 1][x] == 'E')
			return (0);
	}
	else if (move == 'A')
	{
		if (game->map.map[y][x - 1] == '1'
			|| game->map.map[y][x - 1] == 'E')
			return (0);
	}
	else if (move == 'S')
	{
		if (game->map.map[y + 1][x] == '1'
			|| game->map.map[y + 1][x] == 'E')
			return (0);
	}
	else if (move == 'D')
	{
		if (game->map.map[y][x + 1] == '1'
			|| game->map.map[y][x + 1] == 'E')
			return (0);
	}
	return (1);
}

void	move_player(t_game *game, char move)
{
	int	x;
	int	y;

	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
	if (check_walls(game, move, x, y))
		update_pos(game, move, x, y);
}

void	ft_key_hook(mlx_key_data_t key, void *param)
{
	t_game	*game;

	game = param;
	if ((key.key == MLX_KEY_ESCAPE || key.key == MLX_KEY_Q) && key.action == MLX_PRESS)
	{
		ft_freegame(game);
		mlx_terminate(game->mlx);
		ft_printf("Exit game . . .❌🔌\n");
		exit(EXIT_SUCCESS);
	}
	else if ((key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
		&& key.action == MLX_PRESS)
		move_player(game, 'W');
	else if ((key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
		&& key.action == MLX_PRESS)
		move_player(game, 'A');
	else if ((key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		&& key.action == MLX_PRESS)
		move_player(game, 'S');
	else if ((key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
		&& key.action == MLX_PRESS)
		move_player(game, 'D');
	//if (game->map.coin)
	//finish_game();
}

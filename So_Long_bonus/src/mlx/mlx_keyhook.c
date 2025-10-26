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

static void	update_pos(t_game *game, char move, int x, int y)
{
	mlx_image_to_window(game->mlx, game->images->floor, x * 64, y * 64);
	if (move == 'W')
		mlx_image_to_window(game->mlx, game->images->player->pup,
			x * 64, --y * 64);
	else if (move == 'A')
		mlx_image_to_window(game->mlx, game->images->player->pleft,
			--x * 64, y * 64);
	else if (move == 'S')
		mlx_image_to_window(game->mlx, game->images->player->pdown,
			x * 64, ++y * 64);
	else if (move == 'D')
		mlx_image_to_window(game->mlx, game->images->player->pright,
			++x * 64, y * 64);
	game->map.player_pos.x = x;
	game->map.player_pos.y = y;
}

static int	check_walls(t_map *map, char move, int x, int y)
{
	if (move == 'W')
	{
		if (map->map[y - 1][x] == '1'
			|| (map->map[y - 1][x] == 'E' && map->coin != 0))
			return (0);
	}
	else if (move == 'A')
	{
		if (map->map[y][x - 1] == '1'
			|| (map->map[y][x - 1] == 'E' && map->coin != 0))
			return (0);
	}
	else if (move == 'S')
	{
		if (map->map[y + 1][x] == '1'
			|| (map->map[y + 1][x] == 'E' && map->coin != 0))
			return (0);
	}
	else if (move == 'D')
	{
		if (map->map[y][x + 1] == '1'
			|| (map->map[y][x + 1] == 'E' && map->coin != 0))
			return (0);
	}
	return (1);
}

static int	check_enemy(t_map *map, char move, int x, int y)
{
	if (move == 'W')
	{
		if (map->map[y - 1][x] == 'M')
			return (1);
	}
	else if (move == 'A')
	{
		if (map->map[y][x - 1] == 'M')
			return (1);
	}
	else if (move == 'S')
	{
		if (map->map[y + 1][x] == 'M')
			return (1);
	}
	else if (move == 'D')
	{
		if (map->map[y][x + 1] == 'M')
			return (1);
	}
	return (0);
}

static void	move_player(t_game *game, char move)
{
	int	x;
	int	y;

	game->map.moves++;
	x = game->map.player_pos.x;
	y = game->map.player_pos.y;
	if (check_walls(&game->map, move, x, y))
	{
		update_pos(game, move, x, y);
		if (check_enemy(&game->map, move, x, y))
			finish_game(game);
	}
	check_coins(&game->map, move, x, y);
	ft_printf("\x1b[33mcoins left\x1b[0m : [%d]\n", game->map.coin);
	ft_printf("\x1b[31mmoves\x1b[0m : %d\n", game->map.moves);
	ft_printf("y : %d	x : %d\n\n\n",
		game->map.player_pos.y, game->map.player_pos.x);
}

void	ft_key_hook(mlx_key_data_t key, void *param)
{
	t_game	*game;

	game = param;
	if ((key.key == MLX_KEY_ESCAPE || key.key == MLX_KEY_Q)
		&& key.action == MLX_PRESS)
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
	finish_game(game);
}

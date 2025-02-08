/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:22:14 by eduaserr          #+#    #+#             */
/*   Updated: 2025/02/08 04:56:51 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	finish_game(t_game *game)
{
	int	player_y;
	int	player_x;
	int	exit_y;
	int	exit_x;

	player_y = game->map.player_pos.y;
	player_x = game->map.player_pos.x;
	exit_y = game->map.exit_pos.y;
	exit_x = game->map.exit_pos.x;
	if ((player_x == exit_x && player_y == exit_y)
		&& game->map.coin == 0)
	{
		ft_freegame(game);
		mlx_terminate(game->mlx);
		ft_printf("---------------\n");
		ft_printf("------WIN------\n");
		ft_printf("---------------\n");
		exit(EXIT_SUCCESS);
	}
}

void	set_keyimage(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->images->walls, x * 64, y * 64);
	else if (game->map.map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->images->exit, x * 64, y * 64);
	else if (game->map.map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->images->coins, x * 64, y * 64);
	else if (game->map.map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->images->player->pdown,
			x * 64, y * 64);
}

void	get_coin(t_game *game, char **map, int y, int x)
{
	if (map[y][x] == 'C')
		game->map.coin--;
	map[y][x] = '0';
}

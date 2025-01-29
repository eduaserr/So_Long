/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:22:14 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/29 17:30:27 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	set_keyimage(t_game *game, int y, int x)
{
	if (game->map.map[y][x] == '1')
		mlx_image_to_window(game->mlx, game->images.walls, x * 64, y * 64);
	else if (game->map.map[y][x] == 'E')
		mlx_image_to_window(game->mlx, game->images.exit, x * 64, y * 64);
	else if (game->map.map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->images.coins, x * 64, y * 64);
	else if (game->map.map[y][x] == 'P')
		mlx_image_to_window(game->mlx, game->images.player.playerdown, x * 64, y * 64);
}

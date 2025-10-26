/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 03:22:14 by eduaserr          #+#    #+#             */
/*   Updated: 2025/10/26 02:52:41 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_load_enemies(t_game *game, t_img *img, t_txture *txt)
{
	txt->enemies->pdown = mlx_load_png("sprites/enemy_down.png");
	txt->enemies->pup = NULL;
	txt->enemies->pleft = NULL;
	txt->enemies->pright = NULL;
	if (!txt->enemies->pdown)
	{
		ft_freegame(game);
		mlx_terminate(game->mlx);
		ft_error("load img error4");
	}
	img->enemies->pdown = mlx_texture_to_image(game->mlx, txt->enemies->pdown);
	img->enemies->pup = NULL;
	img->enemies->pleft = NULL;
	img->enemies->pright = NULL;
	if (!img->enemies->pdown)
	{
		ft_freegame(game);
		mlx_terminate(game->mlx);
		ft_error("load texture error4");
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
	else if (game->map.map[y][x] == 'M')
		mlx_image_to_window(game->mlx, game->images->enemies->pdown,
			x * 64, y * 64);
}

void	check_coins(t_map *map, char move, int x, int y)
{
	if (move == 'W')
	{
		if (map->map[y - 1][x] == 'C')
		{
			map->coin--;
		}
	}
	else if (move == 'A')
	{
		if (map->map[y][x - 1] == 'C')
			map->coin--;
	}
	else if (move == 'S')
	{
		if (map->map[y + 1][x] == 'C')
			map->coin--;
	}
	else if (move == 'D')
	{
		if (map->map[y][x + 1] == 'C')
			map->coin--;
	}
	map->map[y][x] = '0';
}

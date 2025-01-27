/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:01:29 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/27 03:26:12 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	ft_load_png(t_txture *txture, t_game *game)
{
	txture->coins = mlx_load_png("sprites/coin01.png");
	txture->exit = mlx_load_png("sprites/exit.png");
	if (!txture->coins || !txture->exit)
	{
		ft_freegame(game);
		ft_error("load img error1");
	}
	txture->floor = mlx_load_png("sprites/floor01.png");
	txture->player = mlx_load_png("sprites/player_down01.png");
	if (!txture->floor || !txture->player)
	{
		ft_freegame(game);
		ft_error("load img error2");
	}
	txture->walls = mlx_load_png("sprites/wall03.png");
	if (!txture->walls)
	{
		ft_freegame(game);
		ft_error("load img error3");
	}
}

static void	ft_load_txture(t_game *game, t_img *images, t_txture *txture)
{
	images->coins = mlx_texture_to_image(game->mlx, txture->coins);
	images->exit = mlx_texture_to_image(game->mlx, txture->exit);
	if (!images->coins || !images->exit)
	{
		ft_freegame(game);
		ft_error("load texture error1");
	}
	images->floor = mlx_texture_to_image(game->mlx, txture->floor);
	images->player = mlx_texture_to_image(game->mlx, txture->player);
	if (!txture->coins || !txture->exit)
	{
		ft_freegame(game);
		ft_error("load texture error2");
	}
	images->walls = mlx_texture_to_image(game->mlx, txture->walls);
	if (!images->walls)
	{
		ft_freegame(game);
		ft_error("load texture error3");
	}
}

void	render_map(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < game->map.length)
	{
		x = 0;
		while (x < game->map.width)
		{
			mlx_image_to_window(game->mlx, game->images.floor, x * 64, y * 64);
			set_keyimage(game, y, x);
			x++;
		}
		y++;
	}
}

void	process_images(t_game *game, t_img *images, t_txture *txture)
{
	game->mlx = mlx_init(game->map.width * 64, game->map.length * 64, "So_long", false);
	if (!game->mlx)
	{
		ft_freegame(game);
		ft_error("Mlx init error");
	}
	ft_load_png(txture, game);
	ft_load_txture(game, images, txture);
	render_map(game);
}

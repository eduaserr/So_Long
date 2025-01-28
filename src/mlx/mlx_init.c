/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:01:29 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/28 17:45:41 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	ft_load_png(t_txture *txture, t_game *game)
{
	if (((txture->coins = mlx_load_png("sprites/coin01.png")) == NULL)
		|| ((txture->exit = mlx_load_png("sprites/exit.png")) == NULL))
	{
		ft_freegame(game);
		ft_error("load img error1");
	}
	if (((txture->floor = mlx_load_png("sprites/floor01.png")) == NULL)
		|| ((txture->walls = mlx_load_png("sprites/wall03.png")) == NULL))
	{
		ft_freegame(game);
		ft_error("load img error2");
	}
	txture->player.playerdown = mlx_load_png("sprites/player_down01.png");
	txture->player.playerup = mlx_load_png("sprites/player_up01.png");
	txture->player.playerleft = mlx_load_png("sprites/player_left01.png");
	txture->player.playerright = mlx_load_png("sprites/player_right01.png");
	if (!txture->player.playerdown || !txture->player.playerup
		|| !txture->player.playerleft || !txture->player.playerright)
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
	images->walls = mlx_texture_to_image(game->mlx, txture->walls);
	if (!txture->floor || !txture->walls)
	{
		ft_freegame(game);
		ft_error("load texture error2");
	}
	images->player.playerdown = mlx_texture_to_image(game->mlx, txture->player.playerdown);
	images->player.playerup = mlx_texture_to_image(game->mlx, txture->player.playerup);
	images->player.playerleft = mlx_texture_to_image(game->mlx, txture->player.playerleft);
	images->player.playerright = mlx_texture_to_image(game->mlx, txture->player.playerright);
	if (!images->player.playerdown || !images->player.playerup
		|| !images->player.playerleft || !images->player.playerright)
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

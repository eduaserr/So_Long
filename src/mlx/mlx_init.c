/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:01:29 by eduaserr          #+#    #+#             */
/*   Updated: 2025/02/04 21:43:46 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	ft_load_png(t_txture *txture, t_game *game)
{
	txture->coins = mlx_load_png("sprites/coin01.png");
	txture->exit = mlx_load_png("sprites/exit.png");
	if (!(txture->coins) || (!(txture->exit)))
	{
		ft_freegame(game);
		mlx_terminate(game->mlx);
		ft_error("load img error1");
	}
	txture->floor = mlx_load_png("sprites/floor01.png");
	txture->walls = mlx_load_png("sprites/wall03.png");
	if (!txture->floor || !txture->walls)
	{
		ft_freegame(game);
		mlx_terminate(game->mlx);
		ft_error("load img error2");
	}
}

static void	ft_load_txture(t_game *game, t_img *images, t_txture *txture)
{
	if (!(images->coins = mlx_texture_to_image(game->mlx, txture->coins))
		|| !(images->exit = mlx_texture_to_image(game->mlx, txture->exit)))
	{
		ft_freegame(game);
		mlx_terminate(game->mlx);
		ft_error("load texture error1");
	}
	if (!(images->floor = mlx_texture_to_image(game->mlx, txture->floor))
		|| !(images->walls = mlx_texture_to_image(game->mlx, txture->walls)))
	{
		ft_freegame(game);
		mlx_terminate(game->mlx);
		ft_error("load texture error2");
	}
}

static void	ft_load_player(t_game *game, t_img *img, t_txture *txt)
{
	txt->player->pdown = mlx_load_png("sprites/player_down01.png");
	txt->player->pup = mlx_load_png("sprites/player_up01.png");
	txt->player->pleft = mlx_load_png("sprites/player_left01.png");
	txt->player->pright = mlx_load_png("sprites/player_right01.png");
	if (!txt->player->pdown || !txt->player->pup
		|| !txt->player->pleft || !txt->player->pright)
	{
		ft_freegame(game);
		mlx_terminate(game->mlx);
		ft_error("load img error3");
	}
	img->player->pdown = mlx_texture_to_image(game->mlx, txt->player->pdown);
	img->player->pup = mlx_texture_to_image(game->mlx, txt->player->pup);
	img->player->pleft = mlx_texture_to_image(game->mlx, txt->player->pleft);
	img->player->pright = mlx_texture_to_image(game->mlx, txt->player->pright);
	if (!img->player->pdown || !img->player->pup
		|| !img->player->pleft || !img->player->pright)
	{
		ft_freegame(game);
		mlx_terminate(game->mlx);
		ft_error("load texture error3");
	}
}

static void	render_map(t_game *game)
{
	int y;
	int x;

	y = 0;
	while (y < game->map.length)
	{
		x = 0;
		while (x < game->map.width)
		{
			mlx_image_to_window(game->mlx, game->images->floor, x * 64, y * 64);
			set_keyimage(game, y, x);
			x++;
		}
		y++;
	}
}

void	process_images(t_game *game, t_img *images, t_txture *txture)
{
	game->mlx = mlx_init(game->map.width * 64, game->map.length * 64,
		"So_long", false);
	if (!game->mlx)
	{
		ft_freegame(game);
		mlx_terminate(game->mlx);
		ft_error("Mlx init error");
	}
	ft_load_png(txture, game);
	ft_load_txture(game, images, txture);
	ft_load_player(game, images, txture);
	render_map(game);
}

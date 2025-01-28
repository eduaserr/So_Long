/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:18:18 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/28 17:33:05 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	init_txtures(t_game *game)
{
	game->txture.floor = NULL;
	game->txture.walls = NULL;
	game->txture.coins = NULL;
	game->txture.exit = NULL;
	game->txture.player.playerdown = NULL;
	game->txture.player.playerup = NULL;
	game->txture.player.playerleft = NULL;
	game->txture.player.playerright = NULL;
}

static void	init_values(t_game *game)
{
	game->map.length = 0;
	game->map.width = 0;
	game->map.player = 0;
	game->map.exit = 0;
	game->map.coin = 0;
	game->map.floor = 0;
	game->map.wall = 0;
}

static void	init_img(t_game *game)
{
	game->images.floor = NULL;
	game->images.walls = NULL;
	game->images.coins = NULL;
	game->images.exit = NULL;
	game->images.player.playerdown = NULL;
	game->images.player.playerup = NULL;
	game->images.player.playerleft = NULL;
	game->images.player.playerright = NULL;
}

void	init_struct(t_game *game)
{
	init_values(game);
	init_img(game);
	init_txtures(game);
}

int	check_extension(char **argv)
{
	int	len;

	len = ft_strlen(argv[1]);
	while (argv[1][len - 1] && ft_isspace(argv[1][len - 1]))
		len--;
	if (ft_strncmp(&argv[1][len - 4], ".ber", 4) == 0)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:18:18 by eduaserr          #+#    #+#             */
/*   Updated: 2025/10/26 01:45:45 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static t_txture	*init_txtures(void)
{
	t_txture	*tmp;

	tmp = (t_txture *)malloc(sizeof(t_txture));
	if (!tmp)
		return (NULL);
	tmp->floor = NULL;
	tmp->walls = NULL;
	tmp->coins = NULL;
	tmp->exit = NULL;
	if (player_txtures(tmp))
		return (free(tmp), NULL);
	if (enemy_txtures(tmp))
		return (free(tmp->player), free(tmp), NULL);
	return (tmp);
}

static t_img	*init_img(void)
{
	t_img	*tmp;

	tmp = (t_img *)malloc(sizeof(t_img));
	if (!tmp)
		return (NULL);
	tmp->floor = NULL;
	tmp->walls = NULL;
	tmp->coins = NULL;
	tmp->exit = NULL;
	if (player_img(tmp))
		return (free(tmp), NULL);
	if (enemy_img(tmp))
		return (free(tmp->player), free(tmp), NULL);
	return (tmp);
}

void	init_values(t_game *game)
{
	game->mlx = NULL;
	game->window = NULL;
	game->map.cpymap = NULL;
	game->map.enemies_pos = NULL;
	game->map.length = 0;
	game->map.width = 0;
	game->map.player = 0;
	game->map.enemies = 0;
	game->map.exit = 0;
	game->map.coin = 0;
	game->map.floor = 0;
	game->map.wall = 0;
	game->map.moves = 0;
	game->txture = init_txtures();
	game->images = init_img();
	if (!game->txture || !game->txture->player
		|| !game->images || !game->images->player
		|| !game->txture->enemies || !game->images->enemies)
	{
		ft_freegame(game);
		ft_error("init values error");
	}
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

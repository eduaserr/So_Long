/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 02:52:10 by eduaserr          #+#    #+#             */
/*   Updated: 2025/10/26 02:31:51 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static void	victory(t_game *game, int player_x, int player_y)
{
	int	exit_y;
	int	exit_x;

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

static void	defeat(t_game *game, int player_x, int player_y)
{
	t_enemies*	enemy;
	enemy = game->map.enemies_pos;
	
	int i = 0;
	while (i < game->map.enemies)
	{
		if (player_x == enemy[i].x && player_y == enemy[i].y)
		{
			ft_freegame(game);
			mlx_terminate(game->mlx);
			ft_printf("---------------\n");
			ft_printf("-----DEFEAT----\n");
			ft_printf("---------------\n");
			exit(EXIT_SUCCESS);
		}
		i++;
	}
}
void	finish_game(t_game *game)
{
	t_player player;

	player = game->map.player_pos;

	victory(game, player.x, player.y);
	defeat(game, player.x, player.y);
}

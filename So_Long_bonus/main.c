/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:44:10 by eduaserr          #+#    #+#             */
/*   Updated: 2025/10/26 02:45:34 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

/*int		enemy_collision(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.enemies)
	{
		if (game->map.player_pos.x == game->map.enemies_pos[i].x
			&& game->map.player_pos.y == game->map.enemies_pos[i].y)
			return (1);
		i++;
	}
	return (0);
}

static void	game_loop(void *param)
{
	t_game	*game;

	game = param;
	if (enemy_collision(game))
	{
		ft_printf("\x1b[31m💀 GAME OVER - \x1b[0m\n");
		ft_freegame(game);
		mlx_terminate(game->mlx);
		exit(EXIT_SUCCESS);
	}
	finish_game(game);
}*/

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2 || check_extension(argv) == 1)
		ft_error("Invalid arguments");
	get_map(&game, argv[1]);
	check_elements(&game);
	process_images(&game, game.images, game.txture);
	mlx_key_hook(game.mlx, &ft_key_hook, &game);
	//game_loop(game.mlx);
	mlx_loop(game.mlx);
	ft_freegame(&game);
	mlx_terminate(game.mlx);
	ft_printf("Game closed . . . ❌\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:44:10 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/28 02:17:25 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || check_extension(argv) == 1)
		ft_error("Invalid arguments\n");
	check_map(&game, argv[1]);
	ft_printmap(game.map.map);
	ft_freegame(&game);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:44:10 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/19 16:33:53 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

void	ft_error(char *str)
{
	ft_printf(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || check_extension(argv) == 1)
		ft_error("Invalid arguments\n");
	check_map(&game, argv[1]);
	ft_freemap(game.map.map);
	return (0);
}

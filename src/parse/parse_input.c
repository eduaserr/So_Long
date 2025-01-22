/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:18:18 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/22 18:57:22 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	init_struct(t_game *game)
{
	game->map.length = 0;
	game->map.width = 0;
	game->map.player = 0;
	game->map.exit = 0;
	game->map.coin = 0;
	game->map.floor = 0;
	game->map.wall = 0;
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

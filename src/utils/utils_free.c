/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:41:00 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/16 17:33:33 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_freegame(t_game *game)
{
	if (!game || !game->map.map)
		return ;
	ft_freemap(game->map.map);
	if (!game->map.cpymap)
		return ;
	ft_freemap(game->map.cpymap);
}

void	ft_freemap(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

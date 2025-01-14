/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:41:00 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/14 19:05:04 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_freegame(t_game *game)
{
	if (!game)
		return ;
	ft_freemap(game->map.map);
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

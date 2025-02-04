/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 01:23:41 by eduaserr          #+#    #+#             */
/*   Updated: 2025/02/04 17:03:35 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	player_pos(t_map *map, char **filemap)
{
	int	i;
	int	j;

	i = 1;
	while (filemap[i])
	{
		j = 1;
		while ((filemap[i][j]) && i < (map->length - 1) && j < (map->width - 1))
		{
			if (filemap[i][j] == 'P')
			{
				map->player_pos.x = j;
				map->player_pos.y = i;
			}
			j++;
		}
		i++;
	}
}

void	exit_pos(t_map *map, char **filemap)
{
	int	i;
	int	j;

	i = 1;
	while (filemap[i])
	{
		j = 1;
		while ((filemap[i][j]) && i < (map->length - 1) && j < (map->width - 1))
		{
			if (filemap[i][j] == 'E')
			{
				map->exit_pos.x = j;
				map->exit_pos.y = i;
			}
			j++;
		}
		i++;
	}
}

int	check_path(t_map *map, char **cpymap, int y, int x)
{
	if (!cpymap || y < 0 || y >= map->length
		|| x < 0 || x >= map->width || !cpymap[y])
		return (0);
	if (cpymap[y][x] == 'E' && map->exit == 1)
		map->exit--;
	if (cpymap[y][x] == 'C')
		map->coin--;
	if (cpymap[y][x] == '1' || cpymap[y][x] == 'V' || cpymap[y][x] == 'E')
		return (0);
	if (map->coin == 0 && map->exit == 0)
		return (1);
	cpymap[y][x] = 'V';
	if (check_path(map, cpymap, y + 1, x)
		|| check_path(map, cpymap, y - 1, x)
		|| check_path(map, cpymap, y, x - 1)
		|| check_path(map, cpymap, y, x + 1))
		return (1);
	return (0);
}

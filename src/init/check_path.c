/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 01:23:41 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/17 18:40:41 by eduaserr         ###   ########.fr       */
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
	if (!cpymap || y < 0 || x < 0 || !cpymap[y] || !cpymap[y][x])
		return (0);
	if (cpymap[y][x] == '1' || cpymap[y][x] == 'V')
		return (0);
	if (cpymap[y][x] == 'E' && map->coin > 0)
		return (0);
	if (cpymap[y][x] == 'C')
		map->coin--;
	if (cpymap[y][x] == 'E' && map->coin == 0)
		map->exit--;
	cpymap[y][x] = 'V';
	if (map->coin == 0 && map->exit == 0)
		return (1);
	if (check_path(map, cpymap, y + 1, x)
		|| check_path(map, cpymap, y - 1, x)
		|| check_path(map, cpymap, y, x - 1)
		|| check_path(map, cpymap, y, x + 1))
		return (1);
	if (cpymap[y][x] == 'V')
		cpymap[y][x] = '0';
	return (0);
}

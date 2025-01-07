/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 01:23:41 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/07 16:46:52 by eduaserr         ###   ########.fr       */
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

static void	check_path(char **cpymap, int y, int x)
{
	if (!cpymap[y] || !cpymap[y][x])
		return ;
	if (cpymap[y][x] == '1' || cpymap[y][x] == 'V')
		return ;
	if (cpymap[y][x] == 'E')
		return ;
	if (cpymap[y][x] == '0')
		cpymap[y][x] = 'V';
	check_path(cpymap, y + 1, x);
	check_path(cpymap, y - 1, x);
	check_path(cpymap, y, x - 1);
	check_path(cpymap, y, x + 1);
}

void	player_to_exit(t_map *map, char **cpymap)
{
	int	i;
	int	j;

	i = map->player_pos.y;
	j = map->player_pos.x;
	check_path(cpymap, i, j);
}

void	coin_to_exit(t_map *map)
{
	(void)map;
}

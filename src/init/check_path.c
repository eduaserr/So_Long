/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 01:23:41 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/10 17:10:22 by eduaserr         ###   ########.fr       */
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

static int	check_path(char **cpymap, int y, int x)
{
	if (y < 0 || x < 0 || !cpymap[y] || !cpymap[y][x]) // cambiar
		return (0);
	if (cpymap[y][x] == '1' || cpymap[y][x] == 'V')
		return (0);
	if (cpymap[y][x] == 'E')
		return (1);
	if (cpymap[y][x] == '0' || cpymap[y][x] == 'C')
		cpymap[y][x] = 'V';
	if (check_path(cpymap, y + 1, x) || check_path(cpymap, y - 1, x)
		|| check_path(cpymap, y, x - 1) || check_path(cpymap, y, x + 1))
		return (1);
	return (0);
}

void	player_to_exit(t_map *map, char **cpymap)
{
	int	i;
	int	j;

	i = map->player_pos.y;
	j = map->player_pos.x;
	if (!check_path(cpymap, i, j))
		ft_error("Player cannot reach the exit"); // primero libera
}

void	exit_to_coin(t_map *map)
{
	(void)map;
}

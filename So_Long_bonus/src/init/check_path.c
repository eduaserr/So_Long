/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 01:23:41 by eduaserr          #+#    #+#             */
/*   Updated: 2025/10/26 02:01:54 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	init_enemies(t_game *game, t_map *map)
{
	if (map->enemies > 0)
	{
		map->enemies_pos = (t_enemies *)malloc(sizeof(t_enemies) * map->enemies);
		if (!map->enemies_pos)
		{
			ft_freegame(game);
			ft_error("malloc enemies_pos error");
		}
	}
}

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

void	enemies_pos(t_map *map, char **filemap)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 1;
	while (filemap[i])
	{
		j = 1;
		while ((filemap[i][j]) && i < (map->length - 1) && j < (map->width - 1))
		{
			if (filemap[i][j] == 'M')
			{
				map->enemies_pos[k].x = j;
				map->enemies_pos[k].y = i;
				k++;
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
	if (!cpymap || !cpymap[y])
		return (0);
	if (cpymap[y][x] == 'E' && map->exit == 1)
		map->exit--;
	if (cpymap[y][x] == 'C')
		map->coin--;
	if (map->coin == 0 && map->exit == 0)
		return (1);
	if (cpymap[y][x] == '1' || cpymap[y][x] == 'V' || cpymap[y][x] == 'E' || cpymap[y][x] == 'M')
		return (0);
	cpymap[y][x] = 'V';
	if (check_path(map, cpymap, y + 1, x)
		|| check_path(map, cpymap, y - 1, x)
		|| check_path(map, cpymap, y, x - 1)
		|| check_path(map, cpymap, y, x + 1))
		return (1);
	return (0);
}

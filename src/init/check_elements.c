/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:05:10 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/16 18:05:26 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	line_edges(t_game *game)
{
	char	**map;
	int		i;

	i = 0;
	map = game->map.map;
	while (map[0][i] && map[game->map.length - 1][i])
	{
		if (map[0][i] == '1' && map[game->map.length - 1][i] == '1')
			i++;
		else
		{
			ft_freegame(game);
			ft_error("Map must be surrounded by walls");
		}
	}
}

void	column_edges(t_game *game)
{
	char	**map;
	int		i;

	i = 0;
	map = game->map.map;
	while (map[i] && map[i][game->map.width - 1])
	{
		if (map[i][0] == '1' && map[i][game->map.width - 1] == '1')
			i++;
		else
		{
			ft_freegame(game);
			ft_error("Map must be surrounded by walls");
		}
	}
}

static void	count_entities(t_map *map, char **filemap, int i, int j)
{
	if (filemap[i][j] == 'P')
		map->player++;
	else if (filemap[i][j] == '0')
		map->floor++;
	else if (filemap[i][j] == '1')
		map->wall++;
	else if (filemap[i][j] == 'C')
		map->coin++;
	else if (filemap[i][j] == 'E')
		map->exit++;
	else
	{
		ft_freemap(filemap);
		ft_freemap(map->cpymap);
		ft_error("invalid entities map error");
	}
}

void	check_entities(t_map *map, char **filemap)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (filemap[i])
	{
		j = 1;
		while ((filemap[i][j]) && i < (map->length - 1) && j < (map->width - 1))
		{
			count_entities(map, filemap, i, j);
			j++;
		}
		i++;
	}
	if (map->player != 1 || map->exit != 1 || map->coin < 1)
	{
		ft_freemap(filemap);
		ft_freemap(map->cpymap);
		ft_error("Entities count error");
	}
}

void	valid_path(t_game *game, t_map *map)
{
	player_pos(map, map->map);
	exit_pos(map, map->map);
	if (!check_path(map, map->cpymap, map->exit_pos.y, map->exit_pos.x))
	{
		ft_freegame(game);
		ft_error("Checking path error");
	}
	ft_freemap(map->cpymap);
	map->cpymap = ft_arrdup(map->map);
	if (!map->cpymap)
	{
		ft_freegame(game);
		ft_error("Unexpected arrdup error");
	}
}

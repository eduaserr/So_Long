/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:05:10 by eduaserr          #+#    #+#             */
/*   Updated: 2025/02/05 05:07:13 by eduaserr         ###   ########.fr       */
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
	int	coins;

	coins = map->coin;
	player_pos(map, map->map);
	exit_pos(map, map->map);
	if (!check_path(map, map->cpymap, map->player_pos.y, map->player_pos.x))
	{
		ft_freegame(game);
		if (map->coin != 0)
			ft_error("Checking path error, unreachable coins");
		ft_error("Checking path error, unreachable exit");
	}
	map->coin = coins;
	map->cpymap = ft_arrdup(map->map);
	if (!map->cpymap)
	{
		ft_freegame(game);
		ft_error("cpymap error");
	}
}

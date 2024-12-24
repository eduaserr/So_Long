/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:18:18 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/24 01:32:17 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
			ft_freemap(game->map.map);
			ft_error("Map must has to be surrounded by walls\n");
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
			ft_freemap(game->map.map);
			ft_error("Map must has to be surrounded by walls\n");
		}
	}
}

static void	count_entities(t_map map, char **filemap, int i, int j)
{
	map.player = 0;
	map.exit = 0;
	map.coin = 0;
	map.floor = 0;
	map.wall = 0;
	if (filemap[i][j] == 'P')
		map.player++;
	else if (filemap[i][j] == '0')
		map.floor++;
	else if (filemap[i][j] == '1')
		map.wall++;
	else if (filemap[i][j] == 'C')
		map.coin++;
	else if (filemap[i][j] == 'E')
		map.exit++;
	else
	{
		ft_freemap(filemap);
		ft_error("invalid entities map error\n");
	}
}

void	check_entities(t_map map, char **filemap)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (filemap[i])
	{
		j = 1;
		while ((filemap[i][j]) && i < (map.length - 1) && j < (map.width - 1))
		{
			count_entities(map, filemap, i, j);
			j++;
		}
		i++;
	}
	if (map.player != 1 || map.exit != 1 || map.coin < 1 || map.floor < 1)
	{
		ft_freemap(filemap);
		ft_error("Entities error\n");
	}
}

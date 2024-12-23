/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:18:18 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/23 17:55:27 by eduaserr         ###   ########.fr       */
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

static void	line_edges(t_game *game)
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

static void	column_edges(t_game *game)
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

void	check_limits(t_game *game)
{
	line_edges(game);
	column_edges(game);
}

void	check_entities(t_map map, char **filemap)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	(void)map;
	while (filemap[i])
	{
		j = 1;
		while ((filemap[i][j]) && i < (map.length - 1) && j < (map.width - 1))
		{
			if (filemap[i][j] == '0'
			&& filemap[i][j] == 'C'
			&& filemap[i][j] == 'E'
			&& filemap[i][j] == 'P')
			{
				ft_freemap(filemap);
				ft_error("Entities map error\n");
			}
			j++;
		}
		i++;
	}
}

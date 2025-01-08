/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:51:25 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/08 19:03:00 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static char	*get_line(int fd)
{
	char	*superline;
	char	*line;
	int		size_line;

	superline = NULL;
	line = get_next_line(fd);
	if (!line)
	{
		ft_error("Empty map error\n");
	}
	size_line = ft_strlen_sl(line);
	while (line)
	{
		superline = ft_strjoin_gnl(superline, line);
		free(line);
		line = get_next_line(fd);
		if (line && size_line != ft_strlen_sl(line))
		{
			free(line);
			free(superline);
			ft_error("Size map error\n");
		}
	}
	return (superline);
}

static char	**read_map(char *file_map)
{
	char	**map;
	char	*superline;
	int		fd;

	superline = NULL;
	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		ft_error("Open fd error\n");
	superline = get_line(fd);
	if (superline[0] == '\n')
	{
		free(superline);
		ft_error("Line error\n");
	}
	close(fd);
	map = ft_split(superline, '\n');
	free(superline);
	return (map);
}

static void	check_elements(t_game *game)
{
	line_edges(game);
	column_edges(game);
	check_entities(&game->map, game->map.map);
	valid_path(game);
}

void	check_map(t_game *game, char *file_map)
{
	init_struct(game);
	game->map.map = read_map(file_map);
	get_fullmatrixlen(game->map.map, &game->map.length, &game->map.width);
	game->map.cpymap = ft_arrdup(game->map.map, game->map.width, game->map.length);
	if (!game->map.cpymap)
	{
		ft_freegame(game);
		ft_error("Unexpected error\n");
	}
	check_elements(game);
}

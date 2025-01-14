/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:51:25 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/14 17:17:54 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

static char	*get_line(int fd, int *len)
{
	char	*superline;
	char	*line;
	int		size_line;

	size_line = 0;
	superline = NULL;
	line = get_next_line(fd);
	if (line)
		size_line = ft_strlen(line);
	if (size_line != 0)
		*len = 1;
	while (line)
	{
		*len += 1;
		superline = ft_strjoin_gnl(superline, line);
		ft_free_str(&line);
		line = get_next_line(fd);
	}
	superline = ft_strjoin_gnl(superline, line);
	ft_free_str(&line);
	return (superline);
}

static char	**check_superline(char *superline, int len)
{
	char	**map;
	int		i;
	int		len_check;
	int		len_current;

	if (!superline || !superline[0] || superline[0] == '\n')
		return (free(superline), ft_error("Empty map or line error"), NULL);
	map = ft_split(superline, '\n');
	if (!map)
		return (free(superline), ft_error("Only newlines, empty map"), NULL);
	i = 0;
	len_check = ft_strlen(map[i]);
	while (map[++i])
	{
		len_current = ft_strlen(map[i]);
		if (len_check != len_current)
			return (free(superline), ft_freemap(map),
				ft_error("Invalid size error"), NULL);
	}
	if (i > 0 && ft_strlen(map[i]) == 0)
		len--;
	if (len != i)
		return (ft_freemap(map), free(superline),
			ft_error("Empty line error"), NULL);
	return (map);
}

static char	**read_map(char *file_map)
{
	char	**map;
	char	*superline;
	int		fd;
	int		len;

	superline = NULL;
	len = 0;
	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		ft_error("Open fd error");
	superline = get_line(fd, &len);
	close(fd);
	map = check_superline(superline, len);
	free(superline);
	return (map);
}

void	check_elements(t_game *game)
{
	line_edges(game);
	column_edges(game);
	check_entities(&game->map, game->map.map);
	valid_path(game);
}

void	get_map(t_game *game, char *file_map)
{
	init_struct(game);
	game->map.map = read_map(file_map);
	get_fullmatrixlen(game->map.map, &game->map.length, &game->map.width);
	game->map.cpymap = ft_arrdup(game->map.map);
	if (!game->map.cpymap)
	{
		ft_freegame(game);
		ft_error("Unexpected error");
	}
}

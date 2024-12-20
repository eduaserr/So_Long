/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:51:25 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/20 18:56:05 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	printlines(char *str)
{
	if (str)
		ft_printf("line --> %s\n", str);
}

static int	ft_strlen_sl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	**read_map(char *file_map)
{
	char	**map;
	char	*superline;
	char	*line;
	int		size_line;
	int		fd;

	superline = NULL;
	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		ft_error("Open fd error\n");
	line = get_next_line(fd);
	size_line = ft_strlen_sl(line);
	while (line)
	{
		superline = ft_strjoin_gnl(superline, line);
		free(line);
		line = get_next_line(fd);
		if (line && (size_line != ft_strlen_sl(line)))
			ft_error("Size map error\n");
	}
	map = ft_split(superline, '\n');
	free(superline);
	return (map);
}

void	check_map(t_game *game, char *file_map)
{
	game->map.LENGTH = 0;
	game->map.WIDTH = 0;
	game->map.map = read_map(file_map);
	get_fullmatrixlen(game->map.map, &game->map.LENGTH, &game->map.WIDTH);
}

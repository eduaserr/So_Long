/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:51:25 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/19 19:22:28 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	printlines(char *str)
{
	if (str)
		ft_printf("line --> %s\n", str);
}

char	**read_map(char *file_map)
{
	char	**map;
	char	*superline;
	char	*line;
	char	*preline;
	int		fd;
	int		i;

	superline = NULL;
	preline = NULL;
	i = 0;
	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		ft_error("open fd error\n");
	line = get_next_line(fd);
	while (line)
	{
		if (preline && ft_strlen(line) != ft_strlen(preline))
			ft_error("error reading map\n");
		printlines(line);
		superline = ft_strjoin_gnl(superline, line);
		preline = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	ft_printf("---------------\n");
	printlines(superline);
	ft_printf("---------------\n");
	map = ft_split(superline, '\n');
	ft_printmap(map);
	free(superline);
	return (map);
}

void	check_map(t_game *game, char *file_map)
{
	int	len_columns;
	int	len_lines;

	len_columns = 0;
	len_lines = 0;
	game->map.map = read_map(file_map);
	get_fullmatrixlen(game->map.map, len_columns, len_lines);
}

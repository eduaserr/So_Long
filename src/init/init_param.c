/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:05:10 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/18 16:11:00 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

char	**read_map(char *file_map)
{
	char	**map;
	char	*superline;
	char	*line;
	int		fd;
	int		i;

	superline = NULL;
	i = 0;
	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		ft_error("open fd error\n");
	line = get_next_line(fd);
	while (line)
	{
		superline = ft_strjoin_gnl(superline, line);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(superline, '\n');
	ft_printmap(map);
	free(superline);
	return (map);
}

void	init_struct(t_game *game)
{
	game->mlx = 0;
	game->window = 0;
}

void	init_parameters(t_game *game, char *file_map)
{
	game->map.map = read_map(file_map);
	// game_copy
	//init_struct(game); init_struct(&game, sizeof(t_game)) iniciar todos los componenetes de las estructuras
}
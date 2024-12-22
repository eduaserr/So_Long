/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:51:25 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/22 23:47:22 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	get_fullmatrixlen(char **map, int *y, int *x)
{
	int	tmp;

	if (!map)
		return ;
	while (map[*y])
	{
		tmp = 0;
		while (map[*y][tmp++])
			*x = tmp;
		(*y)++;
	}
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

static char	*get_line(int fd)
{
	char 	*superline;
	char 	*line;
	int		size_line;

	superline = NULL;
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		ft_error("Empty line error\n");
	}
	size_line = ft_strlen_sl(line);
	while (line)
	{
		superline = ft_strjoin_gnl(superline, line);
		free(line);
		line = get_next_line(fd);
		if (!line || (size_line != ft_strlen_sl(line)))
		{
			free(line);
			free(superline);
			ft_error("Size map error\n");
		}
	}
	return (superline);
}

char	**read_map(char *file_map)
{
	char	**map;
	char	*superline;
	int		fd;

	superline = NULL;
	fd = open(file_map, O_RDONLY);
	if (fd < 0)
		ft_error("Open fd error\n");
	superline = get_line(fd);
	map = ft_split(superline, '\n');
	free(superline);
	return (map);
}

void	check_map(t_game *game, char *file_map)
{
	game->map.length = 0;
	game->map.width = 0;
	game->map.map = read_map(file_map);
	get_fullmatrixlen(game->map.map, &game->map.length, &game->map.width);
	ft_printf("lenght -> %d || width-> %d\n", game->map.length, game->map.width);
	check_limits(game);
}

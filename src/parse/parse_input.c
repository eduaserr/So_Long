/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:18:18 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/22 02:20:00 by eduaserr         ###   ########.fr       */
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
			ft_error("Map must has to be surrounded by walls\n");
	}
}

void	column_edges(t_game *game)
{
	char	**map;
	int		i;

	i = 0;
	map = game->map.map;
	
	ft_printf("widht -> %d\n", game->map.width);
	while (map[i] && map[i][game->map.width - 1])
	{
		ft_printf("i : %d\n", i);
		ft_printf("column left : %c\n", map[i][0]);
		ft_printf("column right : %c\n", map[i][game->map.width - 1]);
		if (map[i][0] == '1' && map[i][game->map.width - 1] == '1')
			i++;
		else
			ft_error("Map must has to be surrounded by walls\n");
	}
}

void	check_limits(t_game *game)
{
	line_edges(game);
	ft_printf("si llega\n");
	column_edges(game);
	ft_printf("No llega\n");
}
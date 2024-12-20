/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:18:18 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/20 20:08:22 by eduaserr         ###   ########.fr       */
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
	int		j;

	j = 0;
	i = 0;
	map = game->map.map;
	
	while (map[0][i])
	{
		if (map[0][i] == '1')
			i++;
		else
			ft_error("Must has to be surrounded by walls\n");
	}
}

void	column_edges(t_game *game)
{
	(void)game;
}

void	check_limits(t_game *game)
{
	line_edges(game);
	column_edges(game);
}
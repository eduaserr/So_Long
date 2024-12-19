/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:49:39 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/19 19:05:07 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_printmap(char **file_map)
{
	int	i;

	i = 0;
	while (file_map && file_map[i])
		ft_printf("    %s\n", file_map[i++]);
}

void	ft_freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	get_fullmatrixlen(char **map, int y, int x)
{
	int	flag;
	int	n;

	flag = 0;
	if (!map || !map[y])
	return ;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (!flag)
		{
			n = x;
			flag = 1;
		}
		if (n != x)
			ft_error("map limits validation error\n");
		y++;
	}
}

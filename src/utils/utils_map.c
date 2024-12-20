/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:49:39 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/20 19:01:43 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	printlines(char *str)
{
	if (str)
		ft_printf("line --> %s\n", str);
}

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

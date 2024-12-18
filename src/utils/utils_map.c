/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:49:39 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/18 20:51:23 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_printmap(char **file_map)
{
	int	i;

	i = 0;
	while (file_map && file_map[i])
		printf("%s\n", file_map[i++]);
}

void	ft_freemap(t_game *map)
{
	int	i;

	i = 0;
	while (&map[i])
	{
		free(&map[i]);
		i++;
	}
	free(map);
	//asi no es
}

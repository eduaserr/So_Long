/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:49:39 by eduaserr          #+#    #+#             */
/*   Updated: 2025/02/07 18:16:24 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_error(char *str)
{
	ft_printf("\x1b[31m%s\x1B[37m%s\n", "Error : ", str);
	exit(EXIT_FAILURE);
}

void	ft_printlines(char *str) //borrar
{
	if (str)
		ft_printf("line --> %s\n", str);
}

void	ft_printmap(char **file_map) //borrar
{
	int	i;

	i = 0;
	while (file_map && file_map[i])
		ft_printf("    %s\n", file_map[i++]);
}

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

char	**ft_arrdup(char **arr)
{
	char	**dup;
	int		i;

	i = 0;
	while (arr[i])
		i++;
	dup = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		dup[i] = ft_strdup(arr[i]);
		if (!dup[i])
		{
			ft_freemap(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

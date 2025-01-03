/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:49:39 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/28 03:35:10 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_strlen_sl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	ft_error(char *str)
{
	ft_printf(str);
	exit(EXIT_FAILURE);
}

void	printlines(char *str) //borrar
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
	int		len;

	i = 0;
	len = ft_strlen(arr[i]);
	dup = (char **)malloc(sizeof(char *) * (len + 1));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = ft_strdup(arr[i]);
		if (!dup)
		{
			ft_freemap(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

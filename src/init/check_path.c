/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 01:23:41 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/28 02:06:32 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	player_pos(t_map *map, char **filemap)
{
	int	i;
	int	j;

	i = 1;
	while (filemap[i])
	{
		j = 1;
		while ((filemap[i][j]) && i < (map->length - 1) && j < (map->width - 1))
		{
			if (filemap[i][j] == 'P')
			{
				map->player_pos.x = j;
				map->player_pos.y = i;
			}
			j++;
		}
		i++;
	}
}

void	exit_pos(t_map *map, char **filemap)
{
	int	i;
	int	j;

	i = 1;
	while (filemap[i])
	{
		j = 1;
		while ((filemap[i][j]) && i < (map->length - 1) && j < (map->width - 1))
		{
			if (filemap[i][j] == 'E')
			{
				map->exit_pos.x = j;
				map->exit_pos.y = i;
			}
			j++;
		}
		i++;
	}
}

/*static void	check_path()
{
	
}*/

void	player_to_exit(t_map *map, char **filemap)
{
	int	i;
	int	j;

	i = 1;
	while (filemap[i])
	{
		j = 1;
		while ((filemap[i][j]) && i < (map->length - 1) && j < (map->width - 1))
		{
			if (i == map->player_pos.x && j == map->player_pos.y)
			{
				//check_path();
			}
			j++;
		}
		i++;
	}
}

void	coin_to_exit(t_map *map)
{
	(void)map;
}

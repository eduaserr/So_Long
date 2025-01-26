/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 00:41:00 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/26 02:01:27 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

 static void	ft_free_textures(t_txture *textures)
{
	if (textures->coins)
		mlx_delete_texture(textures->coins);
	if (textures->exit)
		mlx_delete_texture(textures->exit);
	if (textures->floor)
		mlx_delete_texture(textures->floor);
	if (textures->player)
		mlx_delete_texture(textures->player);
	if (textures->walls)
		mlx_delete_texture(textures->walls);
}

static void	ft_free_images(t_game *game, t_img *images)
{
	if (images->coins)
		mlx_delete_image(game->mlx, images->coins);
	if (images->exit)
		mlx_delete_image(game->mlx, images->exit);
	if (images->floor)
		mlx_delete_image(game->mlx, images->floor);
	if (images->player)
		mlx_delete_image(game->mlx, images->player);
	if (images->walls)
		mlx_delete_image(game->mlx, images->walls);
}

void	ft_free_mlx(t_game *game)
{
	if (!game)
		return;
	ft_free_textures(&game->txture);
	ft_free_images(game, &game->images);
}

void	ft_freegame(t_game *game)
{
	if (!game || !game->map.map)
		return ;
	ft_freemap(game->map.map);
	if (!game->map.cpymap)
	return ;
	ft_freemap(game->map.cpymap);
	if (&game->images || &game->txture)
		ft_free_mlx(game);
}

void	ft_freemap(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

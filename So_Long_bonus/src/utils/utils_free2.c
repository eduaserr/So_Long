/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 00:06:33 by eduaserr          #+#    #+#             */
/*   Updated: 2025/10/26 00:38:49 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_player_txtures(t_txpos *player)
{
	if (!player)
		return ;
	if (player->pup)
		mlx_delete_texture(player->pup);
	if (player->pdown)
		mlx_delete_texture(player->pdown);
	if (player->pleft)
		mlx_delete_texture(player->pleft);
	if (player->pright)
		mlx_delete_texture(player->pright);
	free(player);
}

void	free_enemy_txtures(t_txpos *enemies)
{
	if (!enemies)
		return ;
	if (enemies->pup)
		mlx_delete_texture(enemies->pup);
	if (enemies->pdown)
		mlx_delete_texture(enemies->pdown);
	if (enemies->pleft)
		mlx_delete_texture(enemies->pleft);
	if (enemies->pright)
		mlx_delete_texture(enemies->pright);
	free(enemies);
}

void	free_player_img(t_game *game, t_pos *player)
{
	if (!player)
		return ;
	if (player->pup)
		mlx_delete_image(game->mlx, player->pup);
	if (player->pdown)
		mlx_delete_image(game->mlx, player->pdown);
	if (player->pleft)
		mlx_delete_image(game->mlx, player->pleft);
	if (player->pright)
		mlx_delete_image(game->mlx, player->pright);
	free(player);
}

void	free_enemy_img(t_game *game, t_pos *enemies)
{
	if (!enemies)
		return ;
	if (enemies->pup)
		mlx_delete_image(game->mlx, enemies->pup);
	if (enemies->pdown)
		mlx_delete_image(game->mlx, enemies->pdown);
	if (enemies->pleft)
		mlx_delete_image(game->mlx, enemies->pleft);
	if (enemies->pright)
		mlx_delete_image(game->mlx, enemies->pright);
	free(enemies);
}

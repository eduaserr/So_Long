/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 23:34:31 by eduaserr          #+#    #+#             */
/*   Updated: 2025/10/26 00:01:02 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int		player_txtures(t_txture *tmp)
{
	tmp->player = (t_txpos *)malloc(sizeof(t_txpos));
	if (!tmp->player)
		return (1);
	tmp->player->pdown = NULL;
	tmp->player->pup = NULL;
	tmp->player->pleft = NULL;
	tmp->player->pright = NULL;
	return (0);
}

int		enemy_txtures(t_txture *tmp)
{
	tmp->enemies = (t_txpos *)malloc(sizeof(t_txpos));
	if (!tmp->enemies)
		return (1);
	tmp->enemies->pdown = NULL;
	tmp->enemies->pup = NULL;
	tmp->enemies->pleft = NULL;
	tmp->enemies->pright = NULL;
	return (0);
}

int		player_img(t_img *tmp)
{
	tmp->player = (t_pos *)malloc(sizeof(t_pos));
	if (!tmp->player)
		return (1);
	tmp->player->pdown = NULL;
	tmp->player->pup = NULL;
	tmp->player->pleft = NULL;
	tmp->player->pright = NULL;
	return (0);
}

int		enemy_img(t_img *tmp)
{
	tmp->enemies = (t_pos *)malloc(sizeof(t_pos));
	if (!tmp->enemies)
		return (1);
	tmp->enemies->pdown = NULL;
	tmp->enemies->pup = NULL;
	tmp->enemies->pleft = NULL;
	tmp->enemies->pright = NULL;
	return (0);
}
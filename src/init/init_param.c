/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:05:10 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/19 17:18:59 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	init_struct(t_game *game)
{
	game->mlx = 0;
	game->window = 0;
}
	// game_copy
	//init_struct(game); init_struct(&game, sizeof(t_game)) iniciar todos los componenetes de las estructuras
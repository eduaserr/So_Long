/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:31:50 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/20 19:10:26 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"

typedef struct s_map
{
	char	**map;
	int		width;
	int		length;
	char	*copy_map;
}		t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_map	map;
}		t_game;

/*	INIT	*/
//	get_map
void	get_fullmatrixlen(char **map, int *y, int *x);

char	**read_map(char *file_map);

void	check_map(t_game *game, char *file_map);

/*	PARSE	*/
//parse_input
int		check_extension(char **argv);

/*	UTILS	*/
//	utils_map
void	ft_error(char *str);

void	printlines(char *str);

void	ft_printmap(char **file_map);

void	ft_freemap(char **map);

#endif
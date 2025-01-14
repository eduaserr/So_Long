/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:31:50 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/14 19:20:47 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"

// agregar path to coin para comprobar que tienes acceso a todas
// agregar .gitignore a so_long (copiar de submodulo libft)

typedef struct s_exit
{
	int	y;
	int	x;
}		t_exit;

typedef struct s_player
{
	int	y;
	int	x;
}		t_player;

typedef struct s_map
{
	char		**map;
	char		**cpymap;
	int			width;
	int			length;
	int			player;
	int			floor;
	int			wall;
	int			coin;
	int			exit;
	t_player	player_pos;
	t_exit		exit_pos;
}		t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_map	map;
}		t_game;

/*	INIT	*/
//	check_elements
void	line_edges(t_game *game);

void	column_edges(t_game *game);

void	check_entities(t_map *map, char **filemap);

void	valid_path(t_game *game);
//	check_path
void	player_pos(t_map *map, char **filemap);

void	exit_pos(t_map *map, char **filemap);

void	player_to_exit(t_map *map, char **cpymap);

void	exit_to_coin(t_map *map);
//	get_map
void	get_map(t_game *game, char *file_map);

void	check_elements(t_game *game);
/*	PARSE	*/
//	parse_input
void	init_struct(t_game *game);

int		check_extension(char **argv);
/*	UTILS	*/
//	utils_free
void	ft_freegame(t_game *game);

void	ft_freemap(char **map);
//	utils_map
void	ft_error(char *str);

void	printlines(char *str);//borrar

void	ft_printmap(char **file_map);//borrar

void	get_fullmatrixlen(char **map, int *y, int *x);

char	**ft_arrdup(char **arr);

#endif
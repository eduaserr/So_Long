/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr <eduaserr@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:31:50 by eduaserr          #+#    #+#             */
/*   Updated: 2024/12/24 02:26:31 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"

typedef struct s_player
{
	int	y;
	int	x;
}		t_player;

typedef struct s_entities
{
	t_player	player_pos;
}		t_entities;

typedef struct s_map
{
	char		**map;
	int			width;
	int			length;
	int			player;
	int			floor;
	int			wall;
	int			coin;
	int			exit;
	t_entities	entities;
}		t_map;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	t_map	map;
}		t_game;

/*	INIT	*/
//	get_map
void	check_map(t_game *game, char *file_map);

void	get_fullmatrixlen(char **map, int *y, int *x);

/*	PARSE	*/
//	parse_input
int		check_extension(char **argv);

void	line_edges(t_game *game);

void	column_edges(t_game *game);

void	check_entities(t_map *map, char **filemap);

//	check_elements
void	valid_path(t_game game);
/*	UTILS	*/
//	utils_map
int		ft_strlen_sl(char *str);

void	ft_error(char *str);

void	printlines(char *str);

void	ft_printmap(char **file_map);

void	ft_freemap(char **map);

#endif
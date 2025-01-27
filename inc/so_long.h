/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:31:50 by eduaserr          #+#    #+#             */
/*   Updated: 2025/01/27 16:20:15 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdbool.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/libft/libft.h"

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

typedef struct s_img
{
	mlx_image_t	*floor;
	mlx_image_t	*walls;
	mlx_image_t	*coins;
	mlx_image_t	*exit;
	mlx_image_t	*player;
}		t_img;

typedef struct s_txture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*walls;
	mlx_texture_t	*coins;
	mlx_texture_t	*exit;
	mlx_texture_t	*player;
}		t_txture;

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
	void		*mlx;
	void		*window;
	t_img		images;
	t_txture	txture;
	t_map		map;
}		t_game;

/*	INIT	*/
//	check_elements
void	line_edges(t_game *game);

void	column_edges(t_game *game);

void	check_entities(t_map *map, char **filemap);

void	valid_path(t_game *game, t_map *map);
//	check_path
void	player_pos(t_map *map, char **filemap);

void	exit_pos(t_map *map, char **filemap);

int		check_path(t_map *map, char **cpymap, int y, int x);
/*	PARSE	*/
//	get_map
void	get_map(t_game *game, char *file_map);

void	check_elements(t_game *game);
//	parse_input
void	init_struct(t_game *game);

int		check_extension(char **argv);
/*	MLX	*/
//	mlx_init
void	render_map(t_game *game);

void	process_images(t_game *game, t_img *images, t_txture *txture);
/*	UTILS	*/
//	utils_free
void	ft_free_mlx(t_game *game);

void	ft_freegame(t_game *game);

void	ft_freemap(char **map);
//	utils_map
void	ft_error(char *str);

void	ft_printlines(char *str);//borrar

void	ft_printmap(char **file_map);//borrar

void	get_fullmatrixlen(char **map, int *y, int *x);

char	**ft_arrdup(char **arr);
//	utils_mlx
void	set_keyimage(t_game *game, int y, int x);

#endif
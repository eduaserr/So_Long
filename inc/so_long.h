/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduaserr < eduaserr@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 19:31:50 by eduaserr          #+#    #+#             */
/*   Updated: 2025/02/18 13:54:40 by eduaserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

typedef struct s_txpos
{
	mlx_texture_t	*pup;
	mlx_texture_t	*pdown;
	mlx_texture_t	*pleft;
	mlx_texture_t	*pright;
}		t_txpos;

typedef struct s_pos
{
	mlx_image_t	*pup;
	mlx_image_t	*pdown;
	mlx_image_t	*pleft;
	mlx_image_t	*pright;
}		t_pos;

typedef struct s_img
{
	mlx_image_t	*floor;
	mlx_image_t	*walls;
	mlx_image_t	*coins;
	mlx_image_t	*exit;
	t_pos		*player;
}		t_img;

typedef struct s_txture
{
	mlx_texture_t	*floor;
	mlx_texture_t	*walls;
	mlx_texture_t	*coins;
	mlx_texture_t	*exit;
	t_txpos			*player;
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
	int			moves;
	t_player	player_pos;
	t_exit		exit_pos;
}		t_map;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_img		*images;
	t_txture	*txture;
	t_map		map;
}		t_game;

/* **************************************** */
/*					INIT					*/
/* **************************************** */
//////////////////////
//	check_elements	//
//////////////////////
/**
 * @brief Check if edge lines limits are consecutive walls '1'.
 * 
 * @param game
 */
void	line_edges(t_game *game);
/**
 * @brief Check if column edges are consecutive walls '1'.
 * 
 * @param game
 */
void	column_edges(t_game *game);
/**
 * @brief Check and count all entities in the map.
 * 
 * @param game Pointer to the game structure.
 * @param map Pointer to the map structure.
 * @param filemap The map file content.
 */
void	check_entities(t_game *game, t_map *map, char **filemap);
/**
 * @brief Validate the path in the map.
 * 
 * @param game Pointer to the game structure.
 * @param map Pointer to the map structure.
 */
void	valid_path(t_game *game, t_map *map);
//////////////////////
//	check_path		//
//////////////////////
/**
 * @brief Get the player position in the map.
 * 
 * @param map Pointer to the map structure.
 * @param filemap The map file content.
 */
void	player_pos(t_map *map, char **filemap);
/**
 * @brief Get the exit position in the map.
 * 
 * @param map Pointer to the map structure.
 * @param filemap The map file content.
 */
void	exit_pos(t_map *map, char **filemap);
/**
 * @brief Check if there is a valid path (flood_fill) for the player to collect all coins and reach the exit.
 * 
 * @param map Pointer to the map structure.
 * @param cpymap Copy of the map.
 * @param y Y-coordinate.
 * @param x X-coordinate.
 * @return int Returns 1 if there is a valid path, otherwise 0.
 */
int		check_path(t_map *map, char **cpymap, int y, int x);
/* **************************************** */
/*					MLX						*/
/* **************************************** */
//////////////////////
//	mlx_init		//
//////////////////////
/**
 * @brief Initializes the MLX42 library, loads textures and images, and renders the map.
 * 
 * @param game Pointer to the game structure.
 * @param images Pointer to the images structure.
 * @param txture Pointer to the textures structure.
 */
void	process_images(t_game *game, t_img *images, t_txture *txture);
//////////////////////
//	mlx_keyhook		//
//////////////////////
/**
 * @brief Handles key press events for player movement and game exit.
 * 
 * @param key Key data.
 * @param param Pointer to the game structure.
 */
void	ft_key_hook(mlx_key_data_t key, void *param);
/**
 * @brief Checks if the player has collected all coins.
 * 
 * @param map Pointer to the map structure.
 * @param move The move direction.
 * @param x X-coordinate.
 * @param y Y-coordinate.
 */
void	check_coins(t_map *map, char move, int x, int y);
/* **************************************** */
/*					PARSE					*/
/* **************************************** */
//////////////////////
//	get_map			//
//////////////////////
/**
 * @brief Reads and processes the map file.
 * 
 * @param game Pointer to the game structure.
 * @param file_map The map file path.
 */
void	get_map(t_game *game, char *file_map);
/**
 * @brief Validates the map elements and ensures the map is surrounded by walls.
 * 
 * @param game Pointer to the game structure.
 */
void	check_elements(t_game *game);
//////////////////////
//	parse_input		//
//////////////////////
/**
 * @brief Initializes game values and structures.
 * 
 * @param game Pointer to the game structure.
 */
void	init_values(t_game *game);
/**
 * @brief Validates the map file extension.
 * 
 * @param argv Command line arguments.
 * @return int Returns 1 if the extension is valid, otherwise 0.
 */
int		check_extension(char **argv);
/*	UTILS	*/
//////////////////////
//	utils_free		//
//////////////////////
/**
 * @brief Frees all allocated memory and resources used by the game.
 * 
 * @param game Pointer to the game structure.
 */
void	ft_freegame(t_game *game);
/**
 * @brief Frees the MLX resources.
 * 
 * @param game Pointer to the game structure.
 */
void	ft_free_mlx(t_game *game);
/**
 * @brief Frees the map memory.
 * 
 * @param map The map to be freed.
 */
void	ft_freemap(char **map);
//////////////////////
//	utils_map		//
//////////////////////
/**
 * @brief Prints an error message and exits the program.
 * 
 * @param str The error message.
 */
void	ft_error(char *str);
/**
 * @brief Prints the map to the console.
 * 
 * @param file_map The map file content.
 */
void	ft_printmap(char **file_map);
/**
 * @brief Prints lines to the console.
 * 
 * @param str The string to be printed.
 */
void	ft_printlines(char *str);
/**
 * @brief Gets the full matrix length of the map.
 * 
 * @param map The map.
 * @param y Pointer to store the Y-coordinate length.
 * @param x Pointer to store the X-coordinate length.
 */
void	get_fullmatrixlen(char **map, int *y, int *x);
/**
 * @brief Duplicates an array of strings.
 * 
 * @param arr The array to be duplicated.
 * @return char** Returns the duplicated array.
 */
char	**ft_arrdup(char **arr);
//////////////////////
//	utils_mlx		//
//////////////////////
/**
 * @brief Ends the game when the player reaches the exit with all coins collected.
 * 
 * @param game Pointer to the game structure.
 */
void	finish_game(t_game *game);
/**
 * @brief Sets the appropriate image for each map element.
 * 
 * @param game Pointer to the game structure.
 * @param y Y-coordinate.
 * @param x X-coordinate.
 */
void	set_keyimage(t_game *game, int y, int x);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:58:59 by olobresh          #+#    #+#             */
/*   Updated: 2024/03/19 12:13:37 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <memory.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define TILE_SIZE 64

# define WALL 49
# define FLOOR 48
# define COLLECTABLE 67
# define PLAYER 80
# define EXIT 69
# define COLLECTED 88
# define PATH 120

# define COLLECTIBLE_XPM "assets/collectable.png"
# define WALL_XPM "assets/wall.png"
# define FLOOR_XPM "assets/floor.png"
# define PLAYER_XPM "assets/hero.png"
# define EXIT_XPM "assets/exit.png"

typedef struct s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct s_map
{
	char			**map;
	int				w;
	int				h;
	t_pos			*collectables;
	t_pos			*exit;
	t_pos			*start;
	int				count_col;
	int				count_ex;
	int				startpos_player;
}					t_map;

typedef struct s_game
{
	t_pos			*player;
	int				pl_up;
	int				pl_down;
	int				pl_left;
	int				pl_right;
	int				step_count;
	int				pl_collect;
	bool			game_over;
}					t_game;

typedef struct s_imgdata
{
	void			*mlx;
	void			*win;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*coll_texture;
	mlx_texture_t	*exit_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*floor_texture;
	mlx_image_t		*player_img;
	mlx_image_t		*coll_img;
	mlx_image_t		*exit_img;
	mlx_image_t		*wall_img;
	mlx_image_t		*floor_img;
	t_map			*map;
	t_game			*game;
}					t_imgdata;

typedef struct s_flood_fill_data
{
	t_map			*map;
	int				*count;
}					t_flood_fill_data;

// Parse map
void				load_and_validate_map(const char *file_path,
						t_imgdata *imgdata);
char				*read_file_to_string(const char *file_path);
void				allocate_map_resources(t_map *map);
void				fill_map_array(t_map *map, char *map_str);
void				load_game_elements_positions(t_imgdata *data);
void				handle_positions(t_imgdata *data, int *coll_idx, int x,
						int y);
int					count_lines(char *str);
int					get_width(char *str);
int					count_collectibles(char *map_str);
char				*concat_and_free(char *file_content, char *temp_line);

// Map Validity
int					check_map_validity(t_imgdata *data);
int					map_contains_valid_chars(t_map *map);
int					validate_map_contents(t_map *map);
int					is_rectangular(t_map *map);
int					map_is_fully_enclosed(t_map *map);
int					check_edges_for_walls(t_map *map, int x, int y);

// Path validity
int					validate_path(t_imgdata *data);
void				flood_fill(t_flood_fill_data *data, int x, int y,
						int *exit_reached);
void				undo_flood(t_map *map);

// Load assets and render
mlx_image_t			*put_image(char *path, t_imgdata *imgdata);
void				create_images(t_imgdata *imgdata);
void				draw_base_layer(t_imgdata *imgdata);
void				draw_dynamic_elements(t_imgdata *imgdata);
void				render_game(t_imgdata *imgdata);

// Moves
int					ft_is_move_valid(t_imgdata *imgdata, int x, int y);
void				handle_collectible(t_imgdata *imgdata, int x, int y);
void				check_exit_condition(t_imgdata *imgdata, int x, int y);
void				update_position(t_imgdata *imgdata, int new_x, int new_y);
void				move_player_up(t_imgdata *imgdata);
void				move_player_down(t_imgdata *imgdata);
void				move_player_left(t_imgdata *imgdata);
void				move_player_right(t_imgdata *imgdata);
void				key_hook(mlx_key_data_t keydata, void *param);
void				redraw_changed_tiles(t_imgdata *imgdata, int old_x,
						int old_y);
void				log_player_steps(t_imgdata *imgdata);

void				clean_map(t_map *map);
void				clean_resources(t_imgdata *imgdata);
int					ft_strcmp(const char *s1, const char *s2);

void				init_game(t_game **game);
void				init_map(t_map **map);
void				init_textures(t_imgdata *imgdata);
void				init_imgdata(t_imgdata **imgdata);
void				arg_check(int argc, char **argv);
void				check_ext(const char *filename);
int					main(int argc, char **argv);

#endif

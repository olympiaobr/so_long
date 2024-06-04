/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:52:20 by olobresh          #+#    #+#             */
/*   Updated: 2024/03/18 19:52:25 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_is_move_valid(t_imgdata *imgdata, int x, int y)
{
	int	tile;

	if (x < 0 || x >= imgdata->map->w || y < 0 || y >= imgdata->map->h)
		return (0);
	tile = imgdata->map->map[y][x];
	return (tile != WALL && tile != PATH);
}

void	handle_collectible(t_imgdata *imgdata, int x, int y)
{
	if (imgdata->map->map[y][x] == COLLECTABLE)
	{
		imgdata->game->pl_collect++;
		imgdata->map->map[y][x] = FLOOR;
	}
}

void	check_exit_condition(t_imgdata *imgdata, int x, int y)
{
	if (imgdata->map->map[y][x] == EXIT)
	{
		if (imgdata->game->pl_collect == imgdata->map->count_col)
		{
			imgdata->game->game_over = true;
			ft_printf("All collectables collected, exit reached. Game over!\n");
		}
		else
		{
			ft_printf("Exit reached but not all collectables are collected.\n");
		}
	}
}

void	update_position(t_imgdata *imgdata, int new_x, int new_y)
{
	int	old_x;
	int	old_y;

	old_x = imgdata->game->player->x;
	old_y = imgdata->game->player->y;
	handle_collectible(imgdata, new_x, new_y);
	imgdata->game->player->x = new_x;
	imgdata->game->player->y = new_y;
	imgdata->game->step_count++;
	redraw_changed_tiles(imgdata, old_x, old_y);
	check_exit_condition(imgdata, new_x, new_y);
	log_player_steps(imgdata);
}

void	redraw_changed_tiles(t_imgdata *imgdata, int old_x, int old_y)
{
	int	new_x;
	int	new_y;

	new_x = imgdata->game->player->x;
	new_y = imgdata->game->player->y;
	if (!(old_x == new_x && old_y == new_y))
	{
		if (imgdata->map->map[old_y][old_x] == EXIT
			&& imgdata->game->pl_collect != imgdata->map->count_col)
		{
			mlx_image_to_window(imgdata->mlx, imgdata->exit_img, old_x
				* TILE_SIZE, old_y * TILE_SIZE);
		}
		else
		{
			mlx_image_to_window(imgdata->mlx, imgdata->floor_img, old_x
				* TILE_SIZE, old_y * TILE_SIZE);
		}
	}
	mlx_image_to_window(imgdata->mlx, imgdata->player_img, new_x * TILE_SIZE,
		new_y * TILE_SIZE);
}

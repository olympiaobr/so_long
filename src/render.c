/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:55:35 by olobresh          #+#    #+#             */
/*   Updated: 2024/03/14 09:31:19 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	draw_base_layer(t_imgdata *imgdata)
{
	int	y;
	int	x;

	y = 0;
	while (y < imgdata->map->h)
	{
		x = 0;
		while (x < imgdata->map->w)
		{
			mlx_image_to_window(imgdata->mlx, imgdata->floor_img, x * TILE_SIZE,
				y * TILE_SIZE);
			if ((int)imgdata->map->map[y][x] == WALL)
			{
				mlx_image_to_window(imgdata->mlx, imgdata->wall_img, x
					* TILE_SIZE, y * TILE_SIZE);
			}
			if (imgdata->map->map[y][x] == EXIT)
			{
				mlx_image_to_window(imgdata->mlx, imgdata->exit_img, x
					* TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}

void	draw_dynamic_elements(t_imgdata *imgdata)
{
	int	y;
	int	x;

	y = 0;
	while (y < imgdata->map->h)
	{
		x = 0;
		while (x < imgdata->map->w)
		{
			if (imgdata->map->map[y][x] == COLLECTABLE)
			{
				mlx_image_to_window(imgdata->mlx, imgdata->coll_img, x
					* TILE_SIZE, y * TILE_SIZE);
			}
			if (imgdata->map->map[y][x] == PLAYER)
			{
				mlx_image_to_window(imgdata->mlx, imgdata->player_img, x
					* TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}

void	render_game(t_imgdata *imgdata)
{
	draw_base_layer(imgdata);
	draw_dynamic_elements(imgdata);
}

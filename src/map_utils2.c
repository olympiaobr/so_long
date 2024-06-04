/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:04:37 by olobresh          #+#    #+#             */
/*   Updated: 2024/03/18 19:04:39 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	allocate_map_grid(t_map *map)
{
	int	i;

	i = 0;
	map->map = (char **)malloc(sizeof(char *) * map->h);
	if (!map->map)
	{
		ft_printf("Failed to allocate memory for map rows.\n");
		exit(EXIT_FAILURE);
	}
	while (i < map->h)
	{
		map->map[i] = (char *)malloc(sizeof(char) * (map->w + 1));
		if (!map->map[i])
		{
			while (--i >= 0)
			{
				free(map->map[i]);
			}
			free(map->map);
			exit(EXIT_FAILURE);
		}
		map->map[i][map->w] = '\0';
		i++;
	}
}

void	allocate_game_elements(t_map *map)
{
	map->collectables = (t_pos *)malloc(sizeof(t_pos) * map->count_col);
	map->exit = (t_pos *)malloc(sizeof(t_pos));
	map->start = (t_pos *)malloc(sizeof(t_pos));
	if (!map->collectables || !map->exit || !map->start)
	{
		ft_printf("Failed to allocate memory for game elements.\n");
		exit(EXIT_FAILURE);
	}
}

void	allocate_map_resources(t_map *map)
{
	allocate_map_grid(map);
	allocate_game_elements(map);
}

void	load_game_elements_positions(t_imgdata *data)
{
	int	y;
	int	x;
	int	coll_idx;

	coll_idx = 0;
	if (!data->map->collectables || !data->map->exit || !data->map->start)
	{
		ft_printf("Failed to allocate memory for game elements.\n");
		exit(EXIT_FAILURE);
	}
	y = 0;
	while (y < data->map->h)
	{
		x = 0;
		while (x < data->map->w)
		{
			handle_positions(data, &coll_idx, x, y);
			x++;
		}
		y++;
	}
}

void	handle_positions(t_imgdata *data, int *coll_idx, int x, int y)
{
	if (data->map->map[y][x] == COLLECTABLE)
	{
		data->map->collectables[*coll_idx].x = x;
		data->map->collectables[*coll_idx].y = y;
		*coll_idx += 1;
	}
	else if (data->map->map[y][x] == PLAYER)
	{
		data->game->player->x = x;
		data->game->player->y = y;
	}
	else if (data->map->map[y][x] == EXIT)
	{
		data->map->exit->x = x;
		data->map->exit->y = y;
	}
}

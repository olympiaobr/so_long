/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:54:42 by olobresh          #+#    #+#             */
/*   Updated: 2024/03/19 10:16:03 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_is_fully_enclosed(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->h)
	{
		if (!check_edges_for_walls(map, 0, y) || !check_edges_for_walls(map,
				map->w - 1, y))
			return (0);
		y++;
	}
	x = 0;
	while (x < map->w)
	{
		if (!check_edges_for_walls(map, x, 0) || !check_edges_for_walls(map, x,
				map->h - 1))
			return (0);
		x++;
	}
	return (1);
}

int	validate_map_contents(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->count_col = 0;
	map->count_ex = 0;
	map->startpos_player = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->map[i][j] == PLAYER)
				map->startpos_player++;
			if (map->map[i][j] == EXIT)
				map->count_ex++;
			if (map->map[i][j] == COLLECTABLE)
				map->count_col++;
			j++;
		}
		i++;
	}
	return (map->startpos_player == 1 && map->count_ex >= 1
		&& map->count_col >= 1);
}

int	map_contains_valid_chars(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->h)
	{
		j = 0;
		while (j < map->w)
		{
			if (map->map[i][j] != WALL && map->map[i][j] != FLOOR
				&& map->map[i][j] != COLLECTABLE && map->map[i][j] != PLAYER
				&& map->map[i][j] != EXIT)
			{
				ft_printf("Invalid char '%c' (ASCII: %d) found at [%d][%d]\n",
					map->map[i][j], (int)map->map[i][j], i, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_validity(t_imgdata *data)
{
	if (!validate_map_contents(data->map))
		return (0);
	if (!map_contains_valid_chars(data->map))
		return (0);
	if (!is_rectangular(data->map))
		return (0);
	if (!map_is_fully_enclosed(data->map))
		return (0);
	return (1);
}

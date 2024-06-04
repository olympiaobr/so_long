/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:14:57 by olobresh          #+#    #+#             */
/*   Updated: 2024/03/18 18:14:58 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	check_edges_for_walls(t_map *map, int x, int y)
{
	int	max_x;
	int	max_y;

	max_x = map->w;
	max_y = map->h;
	if (x < 0 || y < 0 || x >= max_x || y >= max_y)
		return (0);
	if (map->map[y][x] != WALL)
		return (0);
	return (1);
}

int	is_rectangular(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->h)
	{
		col = 0;
		while (col < map->w && map->map[row][col] != -1)
			col++;
		if (col != map->w)
			return (0);
		row++;
	}
	return (1);
}

int	count_lines(char *str)
{
	int	lines;

	lines = 0;
	while (*str)
	{
		if (*str == '\n')
		{
			lines++;
		}
		str++;
	}
	return (lines);
}

int	get_width(char *str)
{
	int	width;

	width = 0;
	while (*str && *str != '\n' && *str != '\r')
	{
		width++;
		str++;
	}
	return (width);
}

int	count_collectibles(char *map_str)
{
	int	count;

	count = 0;
	while (*map_str)
	{
		if (*map_str == COLLECTABLE)
		{
			count++;
		}
		map_str++;
	}
	return (count);
}

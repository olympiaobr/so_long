/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:58:34 by olobresh          #+#    #+#             */
/*   Updated: 2024/03/13 11:58:38 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_coll(t_map *map)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			if (map->map[y][x] == COLLECTABLE)
			{
				count++;
			}
			x++;
		}
		y++;
	}
	return (count);
}

void	undo_flood(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			if (map->map[y][x] == COLLECTED)
				map->map[y][x] = COLLECTABLE;
			else if (map->map[y][x] == PATH)
				map->map[y][x] = FLOOR;
			x++;
		}
		y++;
	}
}

void	flood_fill(t_flood_fill_data *data, int x, int y, int *exit_reached)
{
	if (x < 0 || x >= data->map->w || y < 0 || y >= data->map->h
		|| data->map->map[y][x] == WALL || data->map->map[y][x] == COLLECTED
		|| data->map->map[y][x] == PATH || data->map->map[y][x] == EXIT)
	{
		if (data->map->map[y][x] == EXIT)
			*exit_reached = 1;
		return ;
	}
	if (data->map->map[y][x] == COLLECTABLE)
	{
		(*(data->count))--;
		data->map->map[y][x] = COLLECTED;
	}
	else if (data->map->map[y][x] == FLOOR)
	{
		data->map->map[y][x] = PATH;
	}
	flood_fill(data, x, y + 1, exit_reached);
	flood_fill(data, x, y - 1, exit_reached);
	flood_fill(data, x + 1, y, exit_reached);
	flood_fill(data, x - 1, y, exit_reached);
}

void	perform_path_validation(t_map *map, int *count, int *exit_reached)
{
	t_flood_fill_data	data;
	int					x;
	int					y;

	data.map = map;
	data.count = count;
	y = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			if (map->map[y][x] == PLAYER)
			{
				flood_fill(&data, x, y, exit_reached);
				undo_flood(map);
				return ;
			}
			x++;
		}
		y++;
	}
}

int	validate_path(t_imgdata *data)
{
	int	exit_reached;
	int	count;

	exit_reached = 0;
	count = count_coll(data->map);
	perform_path_validation(data->map, &count, &exit_reached);
	if (count != 0 || exit_reached == 0)
	{
		ft_printf("Error: Path validation failed.\n");
		return (1);
	}
	return (0);
}

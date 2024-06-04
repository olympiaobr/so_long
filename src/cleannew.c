/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleannew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:36:46 by olobresh          #+#    #+#             */
/*   Updated: 2024/03/13 18:36:49 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clean_map(t_map *map)
{
	int	y;

	y = 0;
	if (map != NULL)
	{
		while (y < map->h)
		{
			free(map->map[y]);
			y++;
		}
		free(map->map);
		free(map->collectables);
		free(map->exit);
		free(map->start);
	}
}

void	clean_resources(t_imgdata *imgdata)
{
	if (imgdata != NULL)
	{
		clean_map(imgdata->map);
		if (imgdata->map)
			free(imgdata->map);
		if (imgdata->game)
		{
			if (imgdata->game->player)
				free(imgdata->game->player);
			free(imgdata->game);
		}
		mlx_terminate(imgdata->mlx);
		free(imgdata);
	}
}

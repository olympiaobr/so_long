/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:56:03 by olobresh          #+#    #+#             */
/*   Updated: 2024/03/19 12:16:47 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_textures(t_imgdata *imgdata)
{
	imgdata->player_texture = 0;
	imgdata->coll_texture = 0;
	imgdata->exit_texture = 0;
	imgdata->wall_texture = 0;
	imgdata->floor_texture = 0;
	imgdata->player_img = 0;
	imgdata->coll_img = 0;
	imgdata->exit_img = 0;
	imgdata->wall_img = 0;
	imgdata->floor_img = 0;
}

void	init_map(t_map **map)
{
	*map = (t_map *)malloc(sizeof(t_map));
	if (*map == NULL)
	{
		ft_printf("Failed to allocate memory for map.\n");
		exit(EXIT_FAILURE);
	}
	(*map)->map = 0;
	(*map)->w = 0;
	(*map)->h = 0;
	(*map)->collectables = 0;
	(*map)->exit = 0;
	(*map)->start = 0;
	(*map)->count_col = 0;
	(*map)->count_ex = 0;
	(*map)->startpos_player = 0;
}

void	init_game(t_game **game)
{
	*game = (t_game *)malloc(sizeof(t_game));
	if (*game == NULL)
	{
		ft_printf("Failed to allocate memory for game.\n");
		exit(EXIT_FAILURE);
	}
	(*game)->player = (t_pos *)malloc(sizeof(t_pos));
	if ((*game)->player == NULL)
	{
		ft_printf("Failed to allocate memory for player position.\n");
		exit(EXIT_FAILURE);
	}
	(*game)->player->x = 0;
	(*game)->player->y = 0;
	(*game)->pl_up = 0;
	(*game)->pl_down = 0;
	(*game)->pl_left = 0;
	(*game)->pl_right = 0;
	(*game)->step_count = 0;
	(*game)->pl_collect = 0;
	(*game)->game_over = false;
}

void	log_player_steps(t_imgdata *imgdata)
{
	ft_printf("Steps: %d\n", imgdata->game->step_count);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

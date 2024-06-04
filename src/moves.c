/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:54:56 by olobresh          #+#    #+#             */
/*   Updated: 2024/03/19 12:16:22 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player_up(t_imgdata *imgdata)
{
	int	new_x;
	int	new_y;

	new_x = imgdata->game->player->x;
	new_y = imgdata->game->player->y - 1;
	if (ft_is_move_valid(imgdata, new_x, new_y))
	{
		update_position(imgdata, new_x, new_y);
	}
}

void	move_player_down(t_imgdata *imgdata)
{
	int	new_x;
	int	new_y;

	new_x = imgdata->game->player->x;
	new_y = imgdata->game->player->y + 1;
	if (ft_is_move_valid(imgdata, new_x, new_y))
	{
		update_position(imgdata, new_x, new_y);
	}
}

void	move_player_left(t_imgdata *imgdata)
{
	int	new_x;
	int	new_y;

	new_x = imgdata->game->player->x - 1;
	new_y = imgdata->game->player->y;
	if (ft_is_move_valid(imgdata, new_x, new_y))
	{
		update_position(imgdata, new_x, new_y);
	}
}

void	move_player_right(t_imgdata *imgdata)
{
	int	new_x;
	int	new_y;

	new_x = imgdata->game->player->x + 1;
	new_y = imgdata->game->player->y;
	if (ft_is_move_valid(imgdata, new_x, new_y))
	{
		update_position(imgdata, new_x, new_y);
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_imgdata	*imgdata;

	imgdata = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		clean_resources(imgdata);
		exit(0);
	}
	if (imgdata->game->game_over)
	{
		return ;
	}
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_player_up(imgdata);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_player_down(imgdata);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_player_left(imgdata);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_player_right(imgdata);
	}
}

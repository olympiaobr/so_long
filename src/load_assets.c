/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:55:15 by olobresh          #+#    #+#             */
/*   Updated: 2024/03/19 12:15:56 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

mlx_image_t	*put_image(char *path, t_imgdata *imgdata)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_printf("Failed to load texture from %s\n");
		exit(EXIT_FAILURE);
	}
	image = mlx_texture_to_image(imgdata->mlx, texture);
	if (!image)
	{
		ft_printf("Failed to convert texture to image for %s\n");
		exit(EXIT_FAILURE);
	}
	mlx_delete_texture(texture);
	return (image);
}

void	create_images(t_imgdata *imgdata)
{
	imgdata->floor_img = put_image(FLOOR_XPM, imgdata);
	imgdata->wall_img = put_image(WALL_XPM, imgdata);
	imgdata->coll_img = put_image(COLLECTIBLE_XPM, imgdata);
	imgdata->player_img = put_image(PLAYER_XPM, imgdata);
	imgdata->exit_img = put_image(EXIT_XPM, imgdata);
}

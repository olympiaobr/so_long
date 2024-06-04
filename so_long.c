/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:05:49 by olobresh          #+#    #+#             */
/*   Updated: 2024/03/19 12:14:27 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_imgdata(t_imgdata **imgdata)
{
	*imgdata = (t_imgdata *)malloc(sizeof(t_imgdata));
	if (*imgdata == NULL)
	{
		ft_printf("Failed to allocate memory for imgdata.\n");
		exit(EXIT_FAILURE);
	}
	(*imgdata)->mlx = 0;
	(*imgdata)->win = 0;
	init_textures(*imgdata);
	init_map(&((*imgdata)->map));
	init_game(&((*imgdata)->game));
}

void	check_ext(const char *filename)
{
	const char	*extension;

	extension = ft_strrchr(filename, '.');
	if (!extension || ft_strcmp(extension, ".ber") != 0)
	{
		ft_printf("Error: Map file must have a .ber extension\n");
		exit(EXIT_FAILURE);
	}
}

void	arg_check(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Too many args or no mapfile\n");
		exit (EXIT_FAILURE);
	}
	check_ext(argv[1]);
}

int	main(int argc, char **argv)
{
	t_imgdata	*imgdata;

	arg_check(argc, argv);
	init_imgdata(&imgdata);
	load_and_validate_map(argv[1], imgdata);
	if (validate_path(imgdata) != 0)
	{
		return (EXIT_FAILURE);
	}
	imgdata->mlx = mlx_init(imgdata->map->w * TILE_SIZE, imgdata->map->h
			* TILE_SIZE, "so_Long", false);
	if (!imgdata->mlx)
	{
		ft_printf("Failed to initialize MLX.\n");
		exit(EXIT_FAILURE);
	}
	create_images(imgdata);
	render_game(imgdata);
	mlx_key_hook(imgdata->mlx, key_hook, imgdata);
	mlx_loop(imgdata->mlx);
	clean_resources(imgdata);
	return (EXIT_SUCCESS);
}

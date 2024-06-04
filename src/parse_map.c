/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olobresh <olobresh@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:55:26 by olobresh          #+#    #+#             */
/*   Updated: 2024/03/19 10:16:39 by olobresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_and_validate_map(const char *file_path, t_imgdata *imgdata)
{
	char	*map_str;

	map_str = read_file_to_string(file_path);
	if (!map_str)
	{
		ft_printf("Failed to load map.\n");
		exit(EXIT_FAILURE);
	}
	imgdata->map->h = count_lines(map_str);
	imgdata->map->w = get_width(map_str);
	imgdata->map->count_col = count_collectibles(map_str);
	allocate_map_resources(imgdata->map);
	fill_map_array(imgdata->map, map_str);
	free(map_str);
	if (!check_map_validity(imgdata))
	{
		ft_printf("Map is not valid.\n");
		exit(EXIT_FAILURE);
	}
	load_game_elements_positions(imgdata);
}

char	*concat_and_free(char *file_content, char *temp_line)
{
	char	*new_content;
	size_t	new_size;

	if (!file_content)
	{
		file_content = ft_strdup(temp_line);
		free(temp_line);
		return (file_content);
	}
	new_size = ft_strlen(file_content) + ft_strlen(temp_line) + 1;
	new_content = (char *)malloc(new_size);
	if (new_content == NULL)
	{
		free(file_content);
		free(temp_line);
		return (NULL);
	}
	ft_strlcpy(new_content, file_content, new_size);
	ft_strlcat(new_content, temp_line, new_size);
	free(file_content);
	free(temp_line);
	return (new_content);
}

char	*read_file_to_string(const char *file_path)
{
	int		fd;
	char	*file_content;
	char	*temp_line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file_content = NULL;
	temp_line = get_next_line(fd);
	while (temp_line != NULL)
	{
		file_content = concat_and_free(file_content, temp_line);
		if (file_content == NULL)
			break ;
		temp_line = get_next_line(fd);
	}
	close(fd);
	return (file_content);
}

void	fill_map_array(t_map *map, char *map_str)
{
	int	row;
	int	col;
	int	index;

	row = 0;
	col = 0;
	index = 0;
	while (map_str[index] != '\0')
	{
		if (map_str[index] == '\n')
		{
			row++;
			col = 0;
		}
		else if (map_str[index] != '\r')
		{
			if (row < map->h && col < map->w)
			{
				map->map[row][col] = map_str[index];
				col++;
			}
		}
		index++;
	}
}

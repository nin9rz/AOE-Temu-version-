/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:20:54 by llinares          #+#    #+#             */
/*   Updated: 2024/12/14 01:46:20 by llinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AOE_temu.h"

static int	get_map_size(int *height, int *width)
{
	FILE	*file;
	char	*line;
	size_t	size;

	size = 1;
	*height = 0;
	*width = 0;
	file = fopen("map.feur", "r");
	line = calloc(1,1);
	if (!file)
		return (0);
	while (getline(&line, &size, file) != -1)
	{
		if (!line)
			return (0);
		if (*width == 0)
			*width = strlen(line);
		free(line);
		size = 1;
		*height = *height + 1;
		line = calloc(1,1);
	}
	if (fclose(file) == EOF)
		return (0);
	return (1);
}

int	parse_map(t_data *data)
{
	FILE	*file;
	int		y;
	int		x;
	char	c[2];

	if (!get_map_size(&data->map.height, &data->map.width))
		return (0);
	file = fopen("map.feur", "r");
	data->map.array = calloc(data->map.height, sizeof(t_tile*));
	y = 0;
	x = 0;
	c[1] = 0;
	while (fscanf(file, "%c", &c[0]) != EOF)
	{
		if (c[0] != '\n')
		{
			data->map.array[y] = (t_tile *)calloc(data->map.width, sizeof(t_tile));
			data->map.array[y][x].tile_index = atoi(c);
			data->map.array[y][x].img = &data->textures.array[atoi(c)];
			x++;
		}
		else
		{
			y++;
			x = 0;
		}
	}
	if (fclose(file) == EOF)
		return (0);
	return (1);
}

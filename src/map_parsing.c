/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:20:54 by llinares          #+#    #+#             */
/*   Updated: 2025/01/07 17:41:33 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AOE_temu.h>

static int	mapDim(t_data *data, char *filename)
{
	FILE	*file;
	char	*line;
	size_t	lineLen = 1;

	file = fopen(filename, "r");
	if (!file)
		return (0);
	line = calloc(1, 1);
	while (getline(&line, &lineLen, file) != -1)
	{
		data->map->height ++;
		if (data->map->width == 0)
			data->map->width = strlen(line);
		else if (data->map->width != strlen(line))
		{
			fclose(file);
			return (0);
		}
		free(line);
		line = calloc(1, 1);
		lineLen = 1;
	}
	free(line);
	fclose(file);
	return (1);
}

static t_tile *setupMapLine(t_data *data, char *line)
{
	t_tile	*mapLine;
	int		i = -1;

	mapLine = calloc(data->map->width, sizeof(*mapLine));
	while(++i < data->map->width)
	{
		mapLine[i].status = IDLE;
		mapLine[i].txt = line[i] - '0';
		mapLine[i].health = 10;//    a changer par rapport au troups
		mapLine[i].maxHealth = 10;//    a changer par rapport au troups
	}
	return (mapLine);
}

int	mapParse(t_data *data, char *filename)
{
	FILE	*file;
	char	*line;
	size_t	lineLen = 1;
	int		i = 0;

	if (!mapDim(data, filename))
		return (0);
	data->map->tiles = calloc(data->map->height, sizeof(*data->map->tiles));
	file = fopen(filename, "r");
	if (!file)
		return (0);
	line = calloc(1, 1);
	while (getline(&line, &lineLen, file) != -1)
	{
		data->map->tiles[i] = setupMapLine(data, line);
		free(line);
		line = calloc(1, 1);
		lineLen = 1;
		i ++;
	}
	free(line);
	fclose(file);
	return (1);
}

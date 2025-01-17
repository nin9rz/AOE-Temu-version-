/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:36:04 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/17 19:24:44 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AOE_temu.h>

Texture2D	getTxt(char *path, int width, int height)
{
	Image		tpImage = LoadImage(path);
	Texture2D	Txt;
	ImageResize(&tpImage, width, height);
	Txt = LoadTextureFromImage(tpImage);
	UnloadImage(tpImage);
	return (Txt);
}

void	initTextures(t_data *data)
{
	Image		tpImage;

	data->textures = calloc(1, sizeof(*data->textures));
	data->textures->background = getTxt("textures/background.png", 1010, 1010);
	data->textures->botHud = getTxt("textures/background.png", 801, 188);

	data->textures->txts[0] = getTxt("textures/grass.png", GRIDWIDTH, GRIDHEIGHT);
	data->textures->txts[1] = getTxt("textures/camp.png", GRIDWIDTH, GRIDHEIGHT);
	data->textures->txts[2] = getTxt("textures/tank.png", GRIDWIDTH, GRIDHEIGHT);

	data->textures->bigTxts[0] = getTxt("textures/grass.png", 188, 188);
	data->textures->bigTxts[1] = getTxt("textures/camp.png", 188, 188);
	data->textures->bigTxts[2] = getTxt("textures/tank.png", 188, 188);
}

void	initMap(t_data *data)
{
	data->map = calloc(1, sizeof(*data->map));
	data->map->height = 0;
	data->map->width = 0;
	data->map->cam.x = 10;
	data->map->cam.y = 10;
	data->map->lastHover.x = -1;
	data->map->lastHover.y = -1;
	data->map->lastSelected.x = -1;
	data->map->lastSelected.y = -1;
}

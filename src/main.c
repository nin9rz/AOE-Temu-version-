/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:33:17 by llinares          #+#    #+#             */
/*   Updated: 2025/01/07 17:31:24 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AOE_temu.h>

void	launchRaylib(t_data *data)
{
	InitWindow(1010, 1010, "AOE Temu-Version");
	initTextures(data);
	initMap(data);
	SetTargetFPS(60);
	DisableEventWaiting();
}

void	launchGame(t_data *data)
{
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground((Color){100, 100, 100, 255});
		handleInputs(data);
		handleMouse(data);
		drawScreen(data);
		EndDrawing();
	}
	CloseWindow();
}

void	freeStructs(t_data *data)
{
	int	i = -1;

	UnloadTexture(data->textures->txts[GRASS]);
	UnloadTexture(data->textures->txts[CAMP]);
	UnloadTexture(data->textures->txts[TANK]);
	UnloadTexture(data->textures->bigTxts[GRASS]);
	UnloadTexture(data->textures->bigTxts[CAMP]);
	UnloadTexture(data->textures->bigTxts[TANK]);
	UnloadTexture(data->textures->background);
	UnloadTexture(data->textures->botHud);
	free(data->textures);
	while (++i < data->map->height)
		free(data->map->tiles[i]);
	free(data->map->tiles);
	free(data->map);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.coins = 2147483647;
	if (argc != 2)
	{
		printf("Enter a map chigga\n");
		return (1);
	}
	launchRaylib(&data);
	if (!mapParse(&data, argv[1]))
	{
		printf("Error during parsing\n");
		return (1);
	}
	launchGame(&data);
	freeStructs(&data);
	return (0);
}

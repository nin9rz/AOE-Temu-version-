/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:33:17 by llinares          #+#    #+#             */
/*   Updated: 2025/01/19 15:01:06 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AOE_temu.h>

float SCREENWIDTH = 1010.F;
float SCREENHEIGHT = 1010.F;
float GRIDSIZE = 50.F;
float NBCOLUMN = 50.F;
float NBROW =  50.F;

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

void	launchRaylib(t_data *data)
{
	InitWindow(1010, 1010, "AOE Temu-Version");
	inits(data);
	SetTargetFPS(60);
	DisableEventWaiting();
}

void	launchGame(t_data *data)
{
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground((Color){100, 100, 100, 255});
		if (IsWindowFocused())
		{
			handleMoveKeyInputs(data);
			// handleMoveMouseInputs(data);
			handleMouse(data);
			drawScreen(data);
		}
		EndDrawing();
	}
	freeStructs(data);
	CloseWindow();
}

int	main(int argc, char **argv)
{
	t_data	data;

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
	return (0);
}

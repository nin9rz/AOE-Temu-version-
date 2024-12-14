/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:33:17 by llinares          #+#    #+#             */
/*   Updated: 2024/12/14 01:43:09 by llinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AOE_temu.h"

void	init_textures(t_textures *textures)
{
	textures->nb = 1;
	textures->array = calloc(textures->nb, sizeof(Image));
	textures->array[0] = LoadImage("textures/grass.png");
}

int	main(int argc, char **argv)
{
	t_data *data;

	data = calloc(1, sizeof(t_data));
	init_textures(&data->textures);
	if (!parse_map(data))
		return (1);
	InitWindow(800, 480, "AOE Temu-Version");
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		EndDrawing();	
	}
	CloseWindow();
	return (0);
}

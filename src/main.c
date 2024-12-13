/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:33:17 by llinares          #+#    #+#             */
/*   Updated: 2024/12/13 21:53:22 by llinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AOE_temu.h"

int	main(int argc, char **argv)
{
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

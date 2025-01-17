/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:37:35 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/17 19:25:13 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AOE_temu.h>

static void	showLefthud(t_data *data)
{
	char	*Coins = calloc(11, sizeof(char));
	sprintf(Coins, "%d", data->coins);
	DrawText(Coins, 20, 34, 30, (Color){255,215,0, 255});
	free(Coins);
}

static void	showTileHud(t_data *data)
{
	float	hp = 0;
	float	maxHp = 0;
	char	*healthRatio;

	DrawTexture(data->textures->botHud, 199, 812, (Color){220, 220, 220, 255});
	if (data->map->lastSelected.x != -1)
	{
		DrawTexture(data->textures->bigTxts[GRASS], 199, 812, WHITE);
		if (data->map->tiles[(int)data->map->lastSelected.y][(int)data->map->lastSelected.x].txt != GRASS)
			hp = data->map->tiles[(int)data->map->lastSelected.y][(int)data->map->lastSelected.x].health;
		maxHp = data->map->tiles[(int)data->map->lastSelected.y][(int)data->map->lastSelected.x].maxHealth;
		DrawTexture(data->textures->bigTxts[data->map->tiles[(int)data->map->lastSelected.y][(int)data->map->lastSelected.x].txt], 199, 812, WHITE);
	}
	else if (data->map->lastHover.x != -1)
	{
		DrawTexture(data->textures->bigTxts[GRASS], 199, 812, WHITE);
		if (data->map->tiles[(int)data->map->lastHover.y][(int)data->map->lastHover.x].txt != GRASS)
			hp = data->map->tiles[(int)data->map->lastHover.y][(int)data->map->lastHover.x].health;
		maxHp = data->map->tiles[(int)data->map->lastHover.y][(int)data->map->lastHover.x].maxHealth;
		DrawTexture(data->textures->bigTxts[data->map->tiles[(int)data->map->lastHover.y][(int)data->map->lastHover.x].txt], 199, 812, WHITE);
	}
	if (hp != 0)
	{
		DrawRectangle(397, 832, 400, 24, BLACK);
		DrawRectangle(397, 832, 400.F * (hp / maxHp), 24, RED);
		healthRatio = calloc(8, sizeof(char));
		sprintf(healthRatio, "%d/%d", (int)hp, (int)maxHp);
		DrawText(healthRatio, 805, 833, 25, RED);
		free(healthRatio);
	}
}

static void	showGrid(t_data *data)
{
	int	x;
	int	y = -1;
	int	cx = data->map->cam.x - NBCOLUMN / 2;
	int	cy = data->map->cam.y - NBROW / 2;

	DrawRectangle(199, 9, 802, 802, BLACK);
	while (++y < NBROW)
	{
		x = - 1;
		while (++x < NBCOLUMN)
		{
			if ((x + cx) < 0 || (x + cx) >= data->map->width || (y + cy) < 0 || (y + cy) >= data->map->height)
				continue ;
			if (data->map->tiles[(y + cy)][(x + cx)].status == IDLE)
				DrawTexture(data->textures->txts[GRASS], x * GRIDWIDTH + 200, y * GRIDHEIGHT + 10, WHITE);
			else if (data->map->tiles[(y + cy)][(x + cx)].status == SELECTED)
				DrawTexture(data->textures->txts[GRASS], x * GRIDWIDTH + 200, y * GRIDHEIGHT + 10, GREEN);
			else if (data->map->tiles[(y + cy)][(x + cx)].status == HOVER)
				DrawTexture(data->textures->txts[GRASS], x * GRIDWIDTH + 200, y * GRIDHEIGHT + 10, DARKGREEN);
			if (data->map->tiles[(y + cy)][(x + cx)].txt == CAMP)
				DrawTexture(data->textures->txts[CAMP], x * GRIDWIDTH + 200, y * GRIDHEIGHT + 10, WHITE);
			else if (data->map->tiles[(y + cy)][(x + cx)].txt == TANK)
				DrawTexture(data->textures->txts[TANK], x * GRIDWIDTH + 200, y * GRIDHEIGHT + 10, WHITE);
		}
	}
}

void	drawScreen(t_data *data)
{
	DrawTexture(data->textures->background, 0, 0, (Color){150, 150, 150, 255});
	showTileHud(data);
	showLefthud(data);
	showGrid(data);
}
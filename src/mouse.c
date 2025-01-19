/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:46:31 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/19 15:46:07 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AOE_temu.h>

static void	HandleClicks(t_data *data, Vector2 pos, int isIn)
{
	if (isIn && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
	{
		if (data->map->lastSelected.x != -1 && ((int)data->map->lastSelected.x != pos.x || (int)data->map->lastSelected.y != pos.y))
			data->map->tiles[(int)data->map->lastSelected.y][(int)data->map->lastSelected.x].status = IDLE;
		data->map->lastSelected.x = pos.x;
		data->map->lastSelected.y = pos.y;
		data->map->tiles[(int)pos.y][(int)pos.x].status = SELECTED;
	}
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
	{
		if (data->map->lastSelected.x != -1)
			data->map->tiles[(int)data->map->lastSelected.y][(int)data->map->lastSelected.x].status = IDLE;
		data->map->lastSelected.x = -1;
		data->map->lastSelected.y = -1;
	}
}

void	handleMouse(t_data *data)
{
	Vector2	pos = GetMousePosition();
	// if ((pos.x <= 200 || pos.x >= 1000 || pos.y <= 10 || pos.y >= 810))
	// {
	// 	if (data->map->lastHover.x != -1 && data->map->tiles[(int)data->map->lastHover.y][(int)data->map->lastHover.x].status == HOVER)
	// 	{
	// 		data->map->tiles[(int)data->map->lastHover.y][(int)data->map->lastHover.x].status = IDLE;
	// 		data->map->lastHover.x = -1;
	// 	}
	// 	HandleClicks(data, pos, 0);
	// 	return ;
	// }
	printf("px: %f, py: %f\n", pos.x, pos.y);
	pos.x = pos.x / GRIDSIZE + (data->map->cam.x - NBCOLUMN / 2.F);
	pos.y = pos.y / GRIDSIZE + (data->map->cam.y - NBROW / 2.F);
	// pos.x = (int)(pos.x + 5) / GRIDSIZE + (data->map->cam.x) - NBCOLUMN / 2.F - (data->map->cam.x > 1);
	// pos.y = (int)(pos.y + 5) / GRIDSIZE + (data->map->cam.y) - NBROW / 2.F - (data->map->cam.y > 1);
	printf("x: %f, y: %f, cx: %f, cy: %f\n", pos.x, pos.y, data->map->cam.x, data->map->cam.y);
	if (pos.x < 0 || pos.x >= data->map->width || pos.y < 0 || pos.y >= data->map->height)
	{
		return ;
	}
	if (data->map->lastHover.x != -1 && data->map->tiles[(int)data->map->lastHover.y][(int)data->map->lastHover.x].status == HOVER
		&& ((int)data->map->lastHover.x != pos.x || (int)data->map->lastHover.y != pos.y))
		data->map->tiles[(int)data->map->lastHover.y][(int)data->map->lastHover.x].status = IDLE;
	if (data->map->tiles[(int)pos.y][(int)pos.x].status == IDLE)
	{
		data->map->lastHover.x = pos.x;
		data->map->lastHover.y = pos.y;
		data->map->tiles[(int)pos.y][(int)pos.x].status = HOVER;
	}
	HandleClicks(data, pos, 1);
}

void	handleMoveMouseInputs(t_data *data)
{
	float	nCamX;
	float	nCamY;

	if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
	{
		nCamX = GetMouseDelta().x * (NBCOLUMN / SCREENWIDTH);
		nCamY = GetMouseDelta().y * (NBROW / SCREENHEIGHT);

		if (nCamX < NBCOLUMN / 2.F)
			nCamX = NBCOLUMN / 2.F;
		if (nCamY < NBROW / 2.F)
			nCamY = NBROW / 2.F;




		if (nCamX >= data->map->width - NBCOLUMN / 2.F)
			nCamX = data->map->width - NBCOLUMN / 2.F;
		if (nCamY >= data->map->height - NBROW / 2.F)
			nCamY = data->map->height - NBROW / 2.F;
		// data->map->cam.x = nCamX;
		// data->map->cam.y = nCamY;


		// data->map->cam.x -= nCamX;
		// data->map->cam.y -= nCamY;
		data->map->cam.x -= (data->map->cam.x - nCamX > NBCOLUMN / 2.F ? (data->map->cam.x - nCamX < data->map->width - NBCOLUMN / 2.F ? nCamX : data->map->width - nCamX - (data->map->cam.x - NBCOLUMN / 2.F)) : data->map->cam.x - nCamX - NBCOLUMN / 2.F);
		data->map->cam.y -= (data->map->cam.y - nCamY > NBROW / 2.F ? (data->map->cam.y - nCamY < data->map->height - NBROW / 2.F ? nCamY : data->map->height - nCamY - (data->map->cam.y - NBROW / 2.F)) : data->map->cam.y - nCamY - NBROW / 2.F);

	}
}

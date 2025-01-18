/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:38:24 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/18 15:00:39 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AOE_temu.h>

void	handleMoveKeyInputs(t_data *data)
{
	if (IsKeyDown(KEY_LEFT) && data->map->cam.x > NBROW / 2)
		data->map->cam.x -= 0.5 * (GetFrameTime() * 60);
	else if (IsKeyDown(KEY_RIGHT) && data->map->cam.x < data->map->width - NBROW / 2)
		data->map->cam.x += 0.5 * (GetFrameTime() * 60);
	if (IsKeyDown(KEY_UP) && data->map->cam.y > NBCOLUMN / 2)
		data->map->cam.y -= 0.5 * (GetFrameTime() * 60);
	else if (IsKeyDown(KEY_DOWN) && data->map->cam.y < data->map->height - NBCOLUMN / 2)
		data->map->cam.y += 0.5 * (GetFrameTime() * 60);
}

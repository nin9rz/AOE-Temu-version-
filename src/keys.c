/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:38:24 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/05 18:11:57 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <AOE_temu.h>

void	handleInputs(t_data *data)
{
	if (IsKeyDown(KEY_LEFT) && data->map->cam.x > 0)
		data->map->cam.x --;
	else if (IsKeyDown(KEY_RIGHT) && data->map->cam.x < data->map->width)
		data->map->cam.x ++;
	if (IsKeyDown(KEY_UP) && data->map->cam.y > 0)
		data->map->cam.y --;
	else if (IsKeyDown(KEY_DOWN) && data->map->cam.y < data->map->height)
		data->map->cam.y ++;
}

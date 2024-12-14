/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AOE_temu.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:10:02 by llinares          #+#    #+#             */
/*   Updated: 2024/12/14 01:40:56 by llinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOE_TEMU_H
# define AOE_TEMU_H
# include "raylib.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_tile
{
	int		tile_index;
	Image	*img;
}	t_tile;

typedef struct s_map
{
	t_tile	**array;
	int	width;
	int	height;
}	t_map;

typedef struct s_textures
{
	Image *array;
	int	nb;
}	t_textures;

typedef struct s_data
{
	int			win_width;
	int			win_height;
	t_map		map;
	t_textures	textures;
}	t_data;

/*************************
**		map_parsing.c	**
**************************/

int	parse_map(t_data *data);

#endif

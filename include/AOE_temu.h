/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AOE_temu.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:10:02 by llinares          #+#    #+#             */
/*   Updated: 2025/01/19 15:00:34 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOE_TEMU_H
# define AOE_TEMU_H

# include <raylib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>

# define NBTXT = 3;

extern float SCREENWIDTH;
extern float SCREENHEIGHT;
extern float GRIDSIZE;
extern float GRIDSIZE;
extern float NBCOLUMN;
extern float NBROW;

typedef enum	e_textures
{
	GRASS,
	CAMP,
	TANK,
}	e_textures;

typedef enum	e_status
{
	IDLE,
	HOVER,
	SELECTED,
	SIGHT,
	MOVE,
}	e_status;

typedef struct s_textures
{
	Image		imgs[3];
	Texture2D	txts[3];
	Texture2D	bigTxts[3];
	Texture2D	background;
	Texture2D	botHud;
}	t_textures;

typedef struct	s_tile
{
	e_status	status;
	e_textures	txt;
	int			health;
	int			maxHealth;
}	t_tile;

typedef struct	s_map
{
	t_tile	**tiles;
	int		width;
	int		height;
	Vector2	cam;
	Vector2	lastHover;
	Vector2	lastSelected;
}	t_map;

typedef struct	s_data
{
	t_textures		*textures;
	t_map			*map;
	unsigned int	coins;
}	t_data;



/*************************
**		inits.c			**
**************************/

void	inits(t_data *data);


/*************************
**		map_parsing.c	**
**************************/

int		mapParse(t_data *data, char *filename);


/*************************
**		display.c		**
**************************/

void	drawScreen(t_data *data);


/*************************
**		keys.c			**
**************************/

void	handleMoveKeyInputs(t_data *data);


/*************************
**		mouse.c			**
**************************/

void	handleMouse(t_data *data);
void	handleMoveMouseInputs(t_data *data);

#endif

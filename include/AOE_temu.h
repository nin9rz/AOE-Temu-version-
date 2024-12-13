/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AOE_temu.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 22:10:02 by llinares          #+#    #+#             */
/*   Updated: 2024/12/13 22:14:01 by llinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOE_TEMU_H
# define AOE_TEMU_H
# include "raylib.h"

typedef struct s_map
{
	int	**array;
	int	width;
	int	height;
}	t_map;

typedef struct s_data
{
	int		win_width;
	int		win_height;
	t_map	map;
}	t_data;

#endif

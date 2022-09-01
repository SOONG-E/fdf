/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:19:42 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/01 19:32:15 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <mlx.h>
#include <math.h>

void	rotation_xy(t_map *map, t_coor **coor)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			coor[i][j].y = cos(map->angle_x) * coor[i][j].y - sin(map->angle_x) * coor[i][j].z;
			coor[i][j].z = sin(map->angle_x) * coor[i][j].y + cos(map->angle_x) * coor[i][j].z;
			coor[i][j].x = cos(map->angle_y) * coor[i][j].x - sin(map->angle_y) * coor[i][j].z;
			coor[i][j].z = sin(map->angle_y) * coor[i][j].x + cos(map->angle_y) * coor[i][j].z;
			coor[i][j].x = cos(map->angle_z) * coor[i][j].x - sin(map->angle_z) * coor[i][j].y;
			coor[i][j].y = sin(map->angle_z) * coor[i][j].x + cos(map->angle_z) * coor[i][j].y;
		}
	}	
}

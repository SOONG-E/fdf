/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_coordn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:13:51 by yujelee           #+#    #+#             */
/*   Updated: 2022/11/02 15:59:32 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>

void	rotation(t_map *map, t_coor **coor)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			coor[i][j].y = cos(map->angle_x) * coor[i][j].y - \
			sin(map->angle_x) * coor[i][j].z;
			coor[i][j].z = sin(map->angle_x) * coor[i][j].y + \
			cos(map->angle_x) * coor[i][j].z;
			coor[i][j].x = cos(map->angle_y) * coor[i][j].x - \
			sin(map->angle_y) * coor[i][j].z;
			coor[i][j].z = sin(map->angle_y) * coor[i][j].x + \
			cos(map->angle_y) * coor[i][j].z;
			coor[i][j].x = cos(map->angle_z) * coor[i][j].x - \
			sin(map->angle_z) * coor[i][j].y;
			coor[i][j].y = sin(map->angle_z) * coor[i][j].x + \
			cos(map->angle_z) * coor[i][j].y;
		}
	}
}

void	isometric(t_map *map, t_coor **coor)
{
	double	pre_x;
	double	pre_y;
	int		i;
	int		j;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			pre_x = (coor[i][j].x - coor[i][j].y) * cos(map->angle);
			pre_y = (coor[i][j].x + coor[i][j].y) * sin(map->angle) - \
			coor[i][j].z;
			coor[i][j].x = pre_x;
			coor[i][j].y = pre_y;
		}
	}
}

void	moving_map(t_map *map, t_coor **coor)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = (map->width / 2) - \
	(coor[map->row / 2][map->col / 2].x);
	y = (map->height / 2) - \
	(coor[map->row / 2][map->col / 2].y);
	adjust_center(map, coor);
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			(coor[i][j]).x += map->moving_x + x;
			(coor[i][j]).y += map->moving_y + y;
		}
	}
}

void	adjust_scale(t_map *map, t_coor **coor)
{
	int	i;
	int	j;

	if (map->scale < 0)
		make_scale(map, coor);
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			coor[i][j].x = coor[i][j].x * map->scale;
			coor[i][j].y = coor[i][j].y * map->scale;
			coor[i][j].z = coor[i][j].z * map->scale;
		}
	}
}

t_coor	**init_coordn(t_map *map)
{
	t_coor	**coor;
	int		i;
	int		j;

	coor = (t_coor **)malloc(map->row * sizeof(t_coor *));
	if (!coor)
		error();
	i = -1;
	while (++i < map->row)
	{
		coor[i] = (t_coor *)malloc(map->col * sizeof(t_coor));
		if (!coor[i])
			error();
		j = -1;
		while (++j < map->col)
		{
			coor[i][j].x = j;
			coor[i][j].y = i;
			coor[i][j].z = map->value[i][j].z;
			coor[i][j].color = map->color[i][j];
		}
	}
	return (coor);
}

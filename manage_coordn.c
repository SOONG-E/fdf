/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_coordn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:13:51 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/01 17:04:11 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h> //manage_coordn.c !!!!!!!!!!

void	rotation(t_map *map, t_coor **coor)
{
	double	sin_po;
	double	cos_po;
	double	sin_na;
	int		i;
	int		j;

	sin_po = sin(map->angle_z);
	cos_po = cos(map->angle_z);
	sin_na = sin(-(map->angle_z));
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			coor[i][j].x = coor[i][j].x + (cos_po + sin_po) * coor[i][j].y + (sin_na + cos_po) * map->value[i][j].z;
			coor[i][j].y = (cos_po + sin_na) * coor[i][j].x + coor[i][j].y + (sin_po + cos_po) * map->value[i][j].z;
		}
	}
}

void	isometric(t_map *map, t_coor **coor)
{
	double	pre_x;
	double	pre_y;
	int	i;
	int	j;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			pre_x = (coor[i][j].x - coor[i][j].y) * cos(map->angle_z);
			pre_y = (coor[i][j].x + coor[i][j].y) * sin(map->angle_z) - \
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

	if (map->moving_x < 0)
	{
		map->moving_x = (map->width / 2) - (coor[map->row / 2][map->col / 2].x);
		map->moving_y = (map->height / 2) - (coor[map->row / 2][map->col / 2].y);
	}
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			(coor[i][j]).x += map->moving_x;
			(coor[i][j]).y += map->moving_y;
		}
	}
}

void	adjust_scale(t_map *map, t_coor **coor)
{
	int	i;
	int	j;

	if (map->scale < 0)
		make_scale(map);
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

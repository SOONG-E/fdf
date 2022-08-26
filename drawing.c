/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:20:04 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/26 20:01:19 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h> //drawing.c !!!!!!!!!!!!!
void	drawing_point(t_map *map, t_coor **coor, void *mlx, void *win)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			if (map->color[i][j])
				mlx_pixel_put(mlx, win, coor[i][j].x, coor[i][j].y, map->color[i][j]);
			else
				mlx_pixel_put(mlx, win, coor[i][j].x, coor[i][j].y, 0xFFFFFF);
		}
	}
}

void	point_to_point(t_coor one, t_coor two, void *mlx, void *win)
{
	double	step[2];
	double	d[2];
	double	p;
	t_coor	coor;
	
	if (two.x > one.x)
		step[0] = 0.01;
	else
		step[0] = -0.01;
	if (two.y > one.y)
		step[1] = 0.01;
	else
		step[1] = -0.01;
	d[0] = abs((int)(two.x - one.x));
	d[1] = abs((int)(two.y - one.y));
	coor = one;
	if (abs((int)(d[1] / d[0])) > 1)
	{
		p = 2 * d[0] - d[1];
		while (((one.x <= two.x && coor.x <= two.x) || (one.x >= two.x && coor.x >= two.x)) && ((one.y <= two.y && coor.y <= two.y) || (one.y >= two.y && coor.y >= two.y)))
		{
			if (p < 0)
				p += (2 * d[0]);
			else
			{
				coor.x += step[0];
				p += (2 * (d[0] - d[1]));
			}
				coor.y += step[1];
				mlx_pixel_put(mlx, win, coor.x, coor.y, 0xFFFFFF);
		}
	}
	else
	{
		p = 2 * d[1] - d[0];
		while (((one.x <= two.x && coor.x <= two.x) || (one.x >= two.x && coor.x >= two.x)) && ((one.y <= two.y && coor.y <= two.y) || (one.y >= two.y && coor.y >= two.y)))
		{
			if (p < 0)
				p += (2 * d[1]);
			else
			{
				coor.y += step[1];
				p += (2 * (d[1] - d[0]));
			}
				coor.x += step[0];
				mlx_pixel_put(mlx, win, coor.x, coor.y, 0xFFFFFF);
		}
	}
}

void	drawing_line(t_map *map, t_coor **coor, void *mlx, void *win)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			if (i < map->row - 1)
				point_to_point(coor[i][j], coor[i + 1][j], mlx, win);
			if (j < map->col - 1)
				point_to_point(coor[i][j], coor[i][j + 1], mlx, win);
		}
	}
}

void	drawing(t_map *map, t_coor **coor, void *mlx, void *win)
{
	adjust_scale(map, coor);
	isometric(map, coor);
	//rotation(map, coor);
	moving_map(map, coor);
	drawing_point(map, coor, mlx, win);
	drawing_line(map, coor, mlx, win);
}
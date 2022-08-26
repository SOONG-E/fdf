/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:20:04 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/26 20:54:25 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>

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
				mlx_pixel_put(mlx, win, coor[i][j].x, coor[i][j].y, coor[i][j].y);
			else
				mlx_pixel_put(mlx, win, coor[i][j].x, coor[i][j].y, 0xFFFFFF);
		}
	}
}

void	point_to_point(t_coor one, t_coor two, void *mlx, void *win)
{
	if (fabs((two.y - one.y) / (two.x - one.x)) > 1)
		gredient_over(one, two, mlx, win);
	else
		gredient_under(one, two, mlx, win);
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
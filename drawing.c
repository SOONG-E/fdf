/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:20:04 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/29 21:01:06 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>

void	drawing_point(t_map *map, t_mlx *mlx)
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
				mlx_pixel_put(mlx->mlx, mlx->win, mlx->coor[i][j].x, \
				mlx->coor[i][j].y, mlx->coor[i][j].y);
			else
				mlx_pixel_put(mlx->mlx, mlx->win, mlx->coor[i][j].x, \
				mlx->coor[i][j].y, 0xFFFFFF);
		}
	}
}

void	point_to_point(t_coor one, t_coor two, t_mlx *mlx)
{
	if (fabs((two.y - one.y) / (two.x - one.x)) > 1)
		gredient_over(one, two, mlx->mlx, mlx->win);
	else
		gredient_under(one, two, mlx->mlx, mlx->win);
}

void	drawing_line(t_map *map, t_mlx *mlx)
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
				point_to_point(mlx->coor[i][j], mlx->coor[i + 1][j], mlx);
			if (j < map->col - 1)
				point_to_point(mlx->coor[i][j], mlx->coor[i][j + 1], mlx);
		}
	}
}

void	drawing(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	adjust_scale(mlx->map, mlx->coor);
	isometric(mlx->map, mlx->coor);
	//rotation(map, coor);
	moving_map(mlx->map, mlx->coor);
	drawing_point(mlx->map, mlx);
	drawing_line(mlx->map, mlx);
}

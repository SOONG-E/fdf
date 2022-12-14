/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 13:20:04 by yujelee           #+#    #+#             */
/*   Updated: 2022/11/02 13:02:58 by yujelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>

void	point_to_point(t_coor one, t_coor two, t_mlx *mlx)
{
	if (fabs((two.y - one.y) / (two.x - one.x)) > 1)
		gredient_over(one, two, mlx);
	else
		gredient_under(one, two, mlx);
}

void	draw_line(t_map *map, t_mlx *mlx)
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

void	draw(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.mlx_img);
	get_img(mlx);
	rotation(mlx->map, mlx->coor);
	isometric(mlx->map, mlx->coor);
	adjust_scale(mlx->map, mlx->coor);
	moving_map(mlx->map, mlx->coor);
	draw_line(mlx->map, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img.mlx_img, 0, 0);
}

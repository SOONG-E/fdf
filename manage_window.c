/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:33:04 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/25 19:36:36 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	init_window(void **mlx, void **win)
{	
	*mlx = mlx_init();
	*win = mlx_new_window (mlx, 1500, 1500, "fdf");
}

void	point_pixel(t_map *map, void *mlx, void *win)
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
				mlx_pixel_put(mlx, win, map->value[i][j].x, map->value[i][j].y, map->color[i][j]);
			else
				mlx_pixel_put(mlx, win, map->value[i][j].x, map->value[i][j].y, 0xFFFFFF);
		}
	}
}

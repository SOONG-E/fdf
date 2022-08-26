/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:33:04 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/26 13:56:03 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

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

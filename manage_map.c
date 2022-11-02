/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:11:38 by yujelee           #+#    #+#             */
/*   Updated: 2022/11/02 13:26:10 by yujelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <math.h>
#include <mlx.h>

t_map	init_map(t_map *map, int width, int height)
{
	(*map).row = -1;
	(*map).col = -1;
	(*map).width = width;
	(*map).height = height;
	(*map).moving_x = -1;
	(*map).moving_y = -1;
	(*map).scale = -1.0;
	(*map).angle = (double)(M_PI / 4);
	(*map).angle_x = 0.0;
	(*map).angle_y = 0.0;
	(*map).angle_z = 0.0;
	(*map).value = NULL;
	(*map).color = NULL;
	return (*map);
}

void	get_img(t_mlx *mlx)
{
	mlx->img.mlx_img = mlx_new_image(mlx->mlx, mlx->map->width, \
	mlx->map->height);
	mlx->img.addr = mlx_get_data_addr(mlx->img.mlx_img, \
	&(mlx->img.bpp), &(mlx->img.line_len), &(mlx->img.endian));
}

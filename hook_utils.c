/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:24:21 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/29 20:12:38 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

void	moving_hook(int key, t_mlx *mlx)
{
	if (key == KEY_LEFT)
		mlx->map->moving_x -= 1;
	else if (key == KEY_RIGHT)
		mlx->map->moving_x += 300;
	else if (key == KEY_UP)
		mlx->map->moving_y -= 1;
	else
		mlx->map->moving_y += 1;
}

void	change_angle(int key, t_mlx *mlx)
{
	if (key == KEY_Q)
		mlx->map->angle_x += 0.1;
	else if (key == KEY_A)
		mlx->map->angle_x -= 0.1;
	else if (key == KEY_W)
		mlx->map->angle_y += 0.1;
	else if (key == KEY_S)
		mlx->map->angle_y -= 0.1;
	else if (key == KEY_E)
		mlx->map->angle_z += 0.1;
	else
		mlx->map->angle_z -= 0.1;
}

void	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

void	change_scale(int key, t_mlx *mlx)
{
	if (key == KEY_PLUS)
		mlx->map->scale += 1;
	else
		mlx->map->scale -= 1;
}

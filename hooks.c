/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:29:13 by yujelee           #+#    #+#             */
/*   Updated: 2022/11/02 15:53:56 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

void	moving_hook(int key, t_mlx *mlx)
{
	if (key == KEY_LEFT)
		mlx->map->moving_x -= 5;
	else if (key == KEY_RIGHT)
		mlx->map->moving_x += 5;
	else if (key == KEY_UP)
		mlx->map->moving_y -= 5;
	else
		mlx->map->moving_y += 5;
}

void	change_angle(int key, t_mlx *mlx)
{
	if (key == KEY_Q)
		mlx->map->angle_x += 0.01;
	else if (key == KEY_A)
		mlx->map->angle_x -= 0.01;
	else if (key == KEY_W)
		mlx->map->angle_y += 0.01;
	else if (key == KEY_S)
		mlx->map->angle_y -= 0.01;
	else if (key == KEY_E)
		mlx->map->angle_z += 0.01;
	else
		mlx->map->angle_z -= 0.01;
}

int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

void	change_scale(int key, t_mlx *mlx)
{
	if (key == KEY_PLUS)
		mlx->map->scale *= 1.1;
	else
		mlx->map->scale *= 0.9;
}

void	reinit_coor(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mlx->map->row)
	{
		j = -1;
		while (++j < mlx->map->col)
		{
			mlx->coor[i][j].x = j;
			mlx->coor[i][j].y = i;
			mlx->coor[i][j].z = mlx->map->value[i][j].z;
		}
	}
}

int	hooks(int key, t_mlx *mlx)
{
	if ((KEY_A <= key && key <= KEY_D) || (KEY_Q <= key && key <= KEY_E))
		change_angle(key, mlx);
	else if (KEY_LEFT <= key && key <= KEY_UP)
		moving_hook(key, mlx);
	else if (key == KEY_ESC)
		close_window(mlx);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		change_scale(key, mlx);
	reinit_coor(mlx);
	draw(mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:42:23 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/06 19:01:05 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <mlx.h>
#include <math.h>

void	gredient_over(t_coor o, t_coor t, t_mlx	*mlx)
{
	double	step[2];
	double	d[2];
	double	p;
	t_coor	coor;

	step[0] = 0.1 * ((t.x > o.x) * 2 - 1);
	step[1] = 0.1 * ((t.y > o.y) * 2 - 1);
	d[0] = fabs(t.x - o.x);
	d[1] = fabs(t.y - o.y);
	coor = o;
	p = 2 * d[0] - d[1];
	while (((o.x <= t.x && coor.x <= t.x) || (o.x >= t.x && coor.x >= t.x))
		&& ((o.y <= t.y && coor.y <= t.y) || (o.y >= t.y && coor.y >= t.y)))
	{
		if (p < 0)
			p += (2 * d[0]);
		else
		{
			coor.x += step[0];
			p += (2 * (d[0] - d[1]));
		}
		coor.y += step[1];
		put_pixel(mlx, coor.x, coor.y, 0xffffff);
	}
}

void	gredient_under(t_coor o, t_coor t, t_mlx *mlx)
{
	double	step[2];
	double	d[2];
	double	p;
	t_coor	coor;

	step[0] = 0.1 * ((t.x > o.x) * 2 - 1);
	step[1] = 0.1 * ((t.y > o.y) * 2 - 1);
	d[0] = fabs(t.x - o.x);
	d[1] = fabs(t.y - o.y);
	coor = o;
	p = 2 * d[1] - d[0];
	while (((o.x <= t.x && coor.x <= t.x) || (o.x >= t.x && coor.x >= t.x))
		&& ((o.y <= t.y && coor.y <= t.y) || (o.y >= t.y && coor.y >= t.y)))
	{
		if (p < 0)
			p += (2 * d[1]);
		else
		{
			coor.y += step[1];
			p += (2 * (d[1] - d[0]));
		}
		coor.x += step[0];
		put_pixel(mlx, coor.x, coor.y, 0xffffff);
	}
}

void	put_pixel(t_mlx	*mlx, int x, int y, int color)
{
	char	*pixel;

	if (x >= mlx->map->width || y >= mlx->map->height)
		return ;
	if (x < 0 || y < 0)
		return ;
	pixel = mlx->img.addr + (y * (mlx->img.line_len) \
	+ x * ((mlx->img.bpp) / 8));
	*(int *)pixel = color;
}

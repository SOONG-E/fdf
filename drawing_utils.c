/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:42:23 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/02 11:32:38 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>

int	cal_rgb(t_coor coor, t_coor one, t_coor two, char c)
{
	double	gap;

	gap = sqrt((pow(one.x - coor.x, 2)) + (pow(one.y - coor.y, 2))) / \
	sqrt((pow(one.x - two.x, 2)) + (pow(one.y - two.y, 2)));
	if (c == 'r')
	{
		return ((((two.color >> 16) - (one.color >> 16)) * gap) + \
		(one.color >> 16));
	}
	else if (c == 'g')
		return (((((two.color % 0x10000) >> 8) - \
		((one.color % 0x10000) >> 8)) * gap) + ((one.color % 0x10000) >> 8));
	else
		return ((((two.color % 0x100) - (one.color % 0x100)) * gap) + \
		(one.color % 0x100));
}

int	make_color(t_coor coor, t_coor one, t_coor two)
{
	int	temp;

	if (one.color == two.color)
		return (one.color);
	temp = cal_rgb(coor, one, two, 'r') << 16;
	temp += cal_rgb(coor, one, two, 'g') << 8;
	temp += cal_rgb(coor, one, two, 'b');
	return (temp);
}

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
		coor.color = make_color(coor, o, t);
		put_pixel(mlx, coor.x, coor.y, coor.color);
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
		coor.color = make_color(coor, o, t);
		put_pixel(mlx, coor.x, coor.y, coor.color);
	}
}

void	put_pixel(t_mlx	*mlx, int x, int y, int color)
{
	char	*pixel;

	if (x >= mlx->map->width || y >= mlx->map->height)
		return ;
	pixel = mlx->img.addr + (y * (mlx->img.line_len) \
	+ x * ((mlx->img.bpp) / 8));
	*(int *)pixel = color;
}

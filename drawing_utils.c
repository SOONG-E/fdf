/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:42:23 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/26 21:59:10 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>

/*
int	cal_rgb(t_coor coor, t_coor one, t_coor two, char c)
{
	if (c == 'r')
	{
		if (one.color >> 16 == two.color >> 16)
			return (one.color >> 16);
		return ((((coor.color >> 16) - (one.color >> 16)) / \
		((two.color >> 16) - (one.color >> 16))) + (one.color >> 16));
	}
	else if (c == 'g')
	{
		if (((one.color % 0x10000) >> 8) == ((two.color % 0x10000) >> 8))
			return (((one.color % 0x10000) >> 8));
		return (((((coor.color % 0x10000) >> 8) - ((one.color % 0x10000) >> 8)) / \
		((((two.color % 0x10000)) >> 8) - ((one.color % 0x10000) >> 8))) + ((one.color % 0x10000) >> 8));	
	}
	else
	{
		if ((one.color % 0x100) == (two.color % 0x100))
			return ((one.color % 0x100));
		return ((((coor.color % 0x100) - (one.color % 0x100)) / \
		((two.color % 0x100) - (one.color % 0x100))) + (one.color % 0x100));
	}
}
*/

int	cal_rgb(t_coor coor, t_coor one, t_coor two, char c)
{
	int gap;
	gap = ((sqrt(coor.color) - sqrt(one.color)) / (sqrt(two.color) - sqrt(one.color)));
	if (c == 'r')
	{
		return ((one.color >> 16) * (1 + gap));
	}
	else if (c == 'g')
		return (((one.color % 0x10000) >> 8) * (1 + gap));
	else
		return ((one.color % 0x100) * (1 + gap));
}

int	make_color(t_coor coor, t_coor one, t_coor two)
{
	int temp;
	int gap;

	gap = coor.color = ((sqrt(coor.color) - sqrt(one.color)) / (sqrt(two.color) - sqrt(one.color)));
	
	if (one.color == two.color)
		return (one.color);
	temp = cal_rgb(coor, one, two, 'r') << 16;
	temp += cal_rgb(coor, one, two, 'g') << 8;
	temp += cal_rgb(coor, one, two, 'b');
	return (temp);
}

void	gredient_over(t_coor one, t_coor two, void *mlx, void *win)
{
	double	step[2];
	double	d[2];
	double	p;
	t_coor	coor;
	
	step[0] = 0.1 * ((two.x > one.x) * 2 - 1);
	step[1] = 0.1 * ((two.y > one.y) * 2 - 1);
	d[0] = fabs(two.x - one.x);
	d[1] = fabs(two.y - one.y);
	coor = one;
	p = 2 * d[0] - d[1];
	while (((one.x <= two.x && coor.x <= two.x) || (one.x >= two.x && coor.x >= two.x)) 
		&& ((one.y <= two.y && coor.y <= two.y) || (one.y >= two.y && coor.y >= two.y)))
	{
		if (p < 0)
			p += (2 * d[0]);
		else
		{
			coor.x += step[0];
			p += (2 * (d[0] - d[1]));
		}
			coor.y += step[1];
			coor.color = make_color(coor, one, two);
			//if (two.color != one.color)
			//	coor.color = ((sqrt(coor.color) - sqrt(one.color)) / (sqrt(two.color) - sqrt(one.color))) * one.color;
			mlx_pixel_put(mlx, win, coor.x, coor.y, coor.color);
	}
}

void	gredient_under(t_coor one, t_coor two, void *mlx, void *win)
{
	double	step[2];
	double	d[2];
	double	p;
	t_coor	coor;
	
	step[0] = 0.1 * ((two.x > one.x) * 2 - 1);
	step[1] = 0.1 * ((two.y > one.y) * 2 - 1);
	d[0] = fabs(two.x - one.x);
	d[1] = fabs(two.y - one.y);
	coor = one;
	p = 2 * d[1] - d[0];
	while (((one.x <= two.x && coor.x <= two.x) || (one.x >= two.x && coor.x >= two.x)) 
		&& ((one.y <= two.y && coor.y <= two.y) || (one.y >= two.y && coor.y >= two.y)))
	{
		if (p < 0)
			p += (2 * d[1]);
		else
		{
			coor.y += step[1];
			p += (2 * (d[1] - d[0]));
		}
			coor.x += step[0];
			coor.color = make_color(coor, one, two);
			//if (two.color != one.color)
			//coor.color = ((sqrt(coor.color) - sqrt(one.color)) / (sqrt(two.color) - sqrt(one.color))) * one.color;
				//coor.color = (coor.color - one.color) / (two.color - one.color) + one.color;
			mlx_pixel_put(mlx, win, coor.x, coor.y, coor.color);
	}
}

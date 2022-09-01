/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:42:23 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/01 19:00:04 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <mlx.h>
#include <math.h>

int	cal_rgb(t_coor coor, t_coor one, t_coor two, char c)
{
	double	gap;
	
	gap = sqrt((pow(one.x - coor.x, 2)) + (pow(one.y - coor.y, 2))) / sqrt((pow(one.x - two.x, 2)) + (pow(one.y - two.y, 2)));
	if (c == 'r')
	{
		return ((((two.color >> 16) - (one.color >> 16)) * gap) + (one.color >> 16));
	}
	else if (c == 'g')
		return (((((two.color % 0x10000) >> 8) - ((one.color % 0x10000) >> 8)) * gap) + ((one.color % 0x10000) >> 8));
	else
		return ((((two.color % 0x100) - (one.color % 0x100)) * gap) + (one.color % 0x100));
}

int	make_color(t_coor coor, t_coor one, t_coor two)
{
	int temp;

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
			mlx_pixel_put(mlx, win, coor.x, coor.y, coor.color);
	}
}

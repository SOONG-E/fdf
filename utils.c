/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:10:56 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/02 18:48:18 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		++count;
	return (count);
}

int	count_line(int fd)
{
	int	count;

	count = 0;
	while (get_next_line(fd))
		++count;
	return (count);
}

int	check_filename(char *name)
{
	if (ft_strnstr(&name[ft_strlen(name) - 4], ".fdf", 4))
		return (1);
	return (0);
}

void	make_scale(t_map *map, t_coor **coor)
{
	double	max_x;
	double	max_y;
	int		i;
	int		j;

	max_x = 0.0;
	max_y = 0.0;
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			if (coor[i][j].x > max_x)
				max_x = coor[i][j].x;
			if (coor[i][j].y > max_y)
				max_y = coor[i][j].y;
		}
	}
	map->scale = (map->height / map->row);
	while ((max_x * map->scale) > map->width
		|| (max_y * map->scale) > map->height)
		map->scale -= 0.1;
	map->scale /= 3;
}

void	adjust_center(t_map *map, t_coor **coor)
{
	double	max_x;
	double	max_y;
	int		i;
	int		j;

	max_x = 0.0;
	max_y = 0.0;
	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			if (coor[i][j].x > max_x)
				max_x = coor[i][j].x;
			if (coor[i][j].y > max_y)
				max_y = coor[i][j].y;
		}
	}
	while ((max_x + map->moving_x) > map->width)
		map->moving_x -= 50;
	while ((max_y + map->moving_y) > map->height)
		map->moving_y -= 50;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:36:10 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/26 13:58:58 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdio.h> //fdf.c 지우기!!!!!!!!!!

void	fdf(t_map *map)
{
	void 	*mlx;
	void 	*win;
	t_coor	**coor;

	mlx = mlx_init();
	win = mlx_new_window(mlx, map->width, map->height, "fdf");
	coor = init_coordn(map);
	drawing(map, coor, mlx, win);
	point_pixel(map, mlx, win);
	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (-1);
	map = init_map(&map, 1500, 1500);
	if (!check_filename(av[1]))
		return (-1);
	parsing_file(av[1], &map);
	fdf(&map);

	return (0);
}

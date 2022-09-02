/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:36:10 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/02 12:07:29 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf_bonus.h"
#include <stdio.h> //fdfbonus.c 지우기!!!!!!!!!!

void	fdf(t_map *map)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, map->width, map->height, "fdf");
	mlx.coor = init_coordn(map);
	mlx.map = map;
	mlx.img.mlx_img = mlx_new_image(mlx.mlx, map->width, map->height);
	mlx.img.addr = mlx_get_data_addr(mlx.img.mlx_img, \
	&(mlx.img.bpp), &(mlx.img.line_len), &(mlx.img.endian));
	drawing(&mlx);
	mlx_hook(mlx.win, KEY_PRESS, 0, hooks, &mlx);
	mlx_hook(mlx.win, DESTROY_NOTIFY, 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (-1);
	if (!check_filename(av[1]))
		return (-1);
	map = init_map(&map, 1500, 1000);
	parsing_file(av[1], &map);
	fdf(&map);
	return (0);
}

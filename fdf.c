/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:36:10 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/25 15:13:27 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include <stdio.h> //fdf.c 지우기!!!!!!!!!!

void	fdf(t_map *map)
{
	init_window();
	make_coordn(map);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		return (-1);
	map = init_map(&map);
	if (!check_filename(av[1]))
		return (-1);
	parsing_file(av[1], &map);
	fdf(&map);

	return (0);
}

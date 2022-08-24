/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:36:10 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/24 16:21:00 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_map	map;

	if (ac < 2)
		return (-1);
	map = init_map(&map);
	parsing_file(av[1], &map);
	//fdf(&map);
	return (0);
/*
	//if (ac < 2)
	//	return (-1);
	map = init_map(&map);
	parsing_file("./test_maps/elem-col.fdf", &map);
	//fdf(&map);
	return (0);
*/
}

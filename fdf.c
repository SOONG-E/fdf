/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:36:10 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/24 15:55:36 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map(t_map *map)
{
	
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac < 2)
		return (-1);
	map = init_map(&map);
	parsing_file(av[1], &map);
	fdf(&map);
	return (0);
}

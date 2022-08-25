/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_coordn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:13:51 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/25 19:34:51 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_coordn(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->row)
	{
		j = -1;
		while (++j < map->col)
		{
			(map->value[i][j]).x = j * 200;
			(map->value[i][j]).y = i * 200;
		}
	}
}

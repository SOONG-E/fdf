/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:11:38 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/26 15:12:37 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <math.h>

t_map	init_map(t_map *map, int width, int height)
{
	(*map).row = -1;
	(*map).col = -1;
	(*map).width = width;
	(*map).height = height;
	(*map).scale = -1.0;
	(*map).angle = (double)(M_PI / 6);
	(*map).value = NULL;
	(*map).color = NULL;
	return (*map);
}

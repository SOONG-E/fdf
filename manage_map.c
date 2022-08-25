/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:11:38 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/25 15:12:34 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_map	init_map(t_map *map)
{
	(*map).row = -1;
	(*map).col = -1;
	(*map).value = NULL;
	(*map).color = NULL;
	return (*map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:11:38 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/22 20:18:27 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_map	*init_map(void)
{
	t_map	map;

	map.line = 0;
	map.size = 0;
	map.coordn = NULL;
	return (&map);
}

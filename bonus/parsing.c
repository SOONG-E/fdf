/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:46:43 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/06 19:01:19 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static t_coor	*to_value(char **words, int size)
{
	t_coor	*ret;
	int		idx;

	ret = (t_coor *)ft_calloc(size, sizeof(t_coor));
	if (!ret)
		error();
	idx = -1;
	while (++idx < size)
		(ret[idx]).z = ft_atoi(words[idx]);
	return (ret);
}

static void	spilt_trans(int fd, t_map *map)
{
	int		idx;
	int		size;
	char	**splited;

	map->value = (t_coor **)malloc(map->row * sizeof(t_coor *));
	if (!map->value)
		error();
	idx = -1;
	while (++idx < map->row)
	{
		splited = ft_split(get_next_line(fd), ' ', &size);
		if (map->col == -1)
			map->col = size;
		else if (map->col != size)
			error();
		map->value[idx] = to_value(splited, size);
		free_child(splited, map->col);
	}
}

void	parsing_file(char *file_name, t_map *map)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	map->row = count_line(fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	spilt_trans(fd, map);
	close(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:46:43 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/24 16:04:50 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //parsing.c 지워!

static char	*get_color(char *str)
{
	char	*ret;

	ret = ft_strcpy(ft_strnstr(str, "0x", ft_strlen(str)));
	return (ret);
}

static char	**to_color(char **words, int size)
{
	char	**ret;
	int		idx;

	ret = (char **)malloc(size * sizeof(char *));
	if (!ret)
		error();
	idx = -1;
	while (++idx < size)
		ret[idx] = get_color(words[idx]);
	idx = -1;
	return (ret);
}

static int	*to_coordn(char **words, int size)
{
	int		*ret;
	int		idx;

	ret = (int *)ft_calloc(size, sizeof(int));
	if (!ret)
		error();
	idx = -1;
	while (++idx < size)
		ret[idx] = ft_atoi(words[idx]);
	return (ret);
}

static void	spilt_trans(int fd, t_map *map)
{
	int		idx;
	int		size;
	char	**splited;

	map->coordn = (int **)malloc(map->row * sizeof(int *));
	if (!map->coordn)
		error();
	map->color = (char ***)malloc(map->row * sizeof(char **));
	if (!map->color)
		error();
	idx = -1;
	while (++idx < map->row)
	{
		splited = ft_split(get_next_line(fd), ' ', &size);
		if (map->col == -1)
			map->col = size;
		else if (map->col != size)
			error();
		map->coordn[idx] = to_coordn(splited, size);
		map->color[idx] = to_color(splited, size);
		free_child(splited, map->col);
	}
	printmap(map);

}

void	parsing_file(char *file_name, t_map *map)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	map->row = count_line(fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	spilt_trans(fd, map);
}
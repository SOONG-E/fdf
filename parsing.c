/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:46:43 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/26 11:43:34 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int	get_color(char *str)
{
	char	*ret;
	int		i;
	int		j;
	int		num;
	int		hex;

	ret = ft_strnstr(str, "0x", ft_strlen(str));
	if (!ret)
		return (0xFFFFFF);
	i = ft_strlen(ret) - 1;
	num = 0;
	hex = 1;
	while (i > 1 && ret[i] != 'x')
	{
		j = 0;
		while (j < 16 && ret[i] != "0123456789ABCDEF"[j])
			++j;
		num = num + j * hex;
		hex *= 16;
		--i;
	}
	return (num);
}

static int	*to_color(char **words, int size)
{
	int		*ret;
	int		idx;

	ret = (int *)ft_calloc(size, sizeof(int));
	if (!ret)
		error();
	idx = -1;
	while (++idx < size)
		ret[idx] = get_color(words[idx]);
	idx = -1;
	return (ret);
}

static t_coor	*to_value(char **words, int size)
{
	t_coor		*ret;
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
	map->color = (int **)malloc(map->row * sizeof(int *));
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
		map->value[idx] = to_value(splited, size);
		map->color[idx] = to_color(splited, size);
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
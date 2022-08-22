/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:36:10 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/22 20:28:45 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

int count_line(int fd)
{
	int	count;

	count = 0;
	while (get_next_line(fd))
		++count;
	return (count);
}

int	*split_nbr(char *str, int *size, t_map *map)
{
	char	**words;
	int		*ret;
	int		idx;

	words = ft_split(str, ' ', size);
	if (!map->size)
		map->size = size;
	else if (map->size != size)
		error();
	ret = (int *)malloc((*size) * sizeof(int));
	if (!ret)
		error();
	idx = -1;
	while (++idx < (*size))
		ret[idx] = ft_getnbr(words[idx]);
	return (ret);
}

int	trans_to_int(int fd, t_map *map)
{
	int		idx;
	int		size;

	map->coordn = (int **)malloc(map->line * sizeof(int *));
	if (!map->coordn)
		error();
	idx = -1;
	while (++idx < map->line)
		map->coordn[idx] = split_nbr(get_next_line(fd), &size, map);
	// ㄷㅏ ㅇㅏㄴ하ㅁ
}

void	parsing_file(char **file_name, t_map *map)
{
	int		fd;
	int		line;
	int		**coordn;

	fd = open(file_name, O_RDONLY);
	map->line = count_line(fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
}

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac < 2)
		return ;
	map = init_map();
}
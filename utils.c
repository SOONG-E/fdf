/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 14:10:56 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/25 14:49:26 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h> //utils.c

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		++count;
	return (count);
}

int count_line(int fd)
{
	int	count;

	count = 0;
	while (get_next_line(fd))
		++count;
	return (count);
}

int	check_filename(char *name)
{
	if (ft_strnstr(name, ".fdf\0", ft_strlen(name)))
		return (1);
	return (0);
}

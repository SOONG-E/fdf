/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:27:21 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/22 19:31:42 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void	*ft_memset(void *b, int c, int len)
{
	int	count;

	count = 0;
	while (count < len)
	{
		((unsigned char *)b)[count++] = c;
	}
	return (b);
}

void	*ft_calloc(int count, int size)
{
	unsigned char	*ret;

	ret = (unsigned char *)malloc(count * size);
	if (!ret)
		return (NULL);
	ret = ft_memset(ret, 0, count * size);
	return ((void *)ret);
}

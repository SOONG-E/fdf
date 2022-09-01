/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:02:24 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/26 11:49:23 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdlib.h>

static int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	idx;

	if (!n)
		return (0);
	idx = 0;
	while (s1[idx] == s2[idx] && --n && s1[idx])
		idx++;
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

char	*ft_strnstr(char *haystack, char *needle, int len)
{
	int	idx;
	int	needlelen;

	if (*needle == 0)
		return ((char *)haystack);
	idx = 0;
	needlelen = ft_strlen(needle);
	while (len > idx && haystack[idx])
	{
		if (haystack[idx] == needle[0] && len >= needlelen + idx)
		{
			if (ft_strncmp(&haystack[idx], needle, needlelen) == 0)
				return ((char *)&haystack[idx]);
		}
		idx++;
	}
	return (NULL);
}

char	*ft_strcpy(char *src)
{
	int		idx;
	int		srcsize;
	char	*ret;

	if (!src)
		return (NULL);
	srcsize = ft_strlen(src);
	ret = (char *)malloc((srcsize + 1) * sizeof(char));
	if (!ret)
		error();
	idx = -1;
	while (src[++idx])
		ret[idx] = src[idx];
	ret[idx] = 0;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:33:34 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/25 15:06:36 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(char *str)
{
	long long	idx;
	long long	ret;
	int			s;

	idx = 0;
	ret = 0;
	s = 1;
	while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			s = -1;
		idx++;
	}
	if (!(48 <= str[idx] && str[idx] <= 57))
		error();
	while (48 <= str[idx] && str[idx] <= 57)
	{
		ret = ret * 10 + (str[idx] - 48);
		idx++;
	}
	return ((int)(s * ret));
}

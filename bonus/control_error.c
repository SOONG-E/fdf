/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:50:31 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/22 19:50:33 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

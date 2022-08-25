/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:33:04 by yujelee           #+#    #+#             */
/*   Updated: 2022/08/25 15:41:42 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

void	*init_window(void)
{	
	void	*mlx;

	mlx = mlx_init();
	mlx_loop(mlx);
	return (mlx);
}

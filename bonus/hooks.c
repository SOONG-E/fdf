/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:29:13 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/02 12:27:37 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <mlx.h>
#include <stdio.h> //hooks.c

int	hooks(int key, t_mlx *mlx)
{
	if ((KEY_A <= key && key <= KEY_D) || (KEY_Q <= key && key <= KEY_E))
		change_angle(key, mlx);
	else if (KEY_LEFT <= key && key <= KEY_UP)
		moving_hook(key, mlx);
	else if (key == KEY_ESC)
		close_window(mlx);
	else if (key == KEY_PLUS || key == KEY_MINUS)
		change_scale(key, mlx);
	reinit_coor(mlx);
	drawing(mlx);
	return (0);
}

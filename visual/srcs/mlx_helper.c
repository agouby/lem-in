/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:37:01 by agouby            #+#    #+#             */
/*   Updated: 2017/09/21 21:20:35 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	create_win(t_env *v)
{
	v->mlx.win = mlx_new_window(v->mlx.ptr, WIN_X, WIN_Y, "Lem-in visualizer");
}

void	create_img(t_env *v)
{
	v->mlx.img = mlx_new_image(v->mlx.ptr, WIN_X, WIN_Y);
	v->mlx.pixel_img =
		mlx_get_data_addr(v->mlx.img, &v->mlx.bpp, &v->mlx.s_line, &v->mlx.ed);
}

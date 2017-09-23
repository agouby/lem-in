/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:37:01 by agouby            #+#    #+#             */
/*   Updated: 2017/09/23 01:31:55 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	create_win(t_env *v)
{
	v->mlx.win = mlx_new_window(v->mlx.ptr, WIN_X, WIN_Y, "Lem-in visualizer");
}

void	create_map(t_env *v)
{
	v->mlx.map =
		mlx_new_image(v->mlx.ptr, MAP_X + OFFSET * 2, MAP_Y + OFFSET * 2);
	v->mlx.pixel_img =
		mlx_get_data_addr(v->mlx.map, &v->mlx.bpp, &v->mlx.s_line, &v->mlx.ed);
}

void	start_mlx(t_env *v)
{
	v->mlx.ptr = mlx_init();
	create_win(v);
	create_map(v);
	clear_map(v);
}

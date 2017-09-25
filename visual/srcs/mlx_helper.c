/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:37:01 by agouby            #+#    #+#             */
/*   Updated: 2017/09/25 21:21:29 by agouby           ###   ########.fr       */
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

char	*ret_path(char n)
{
	static char	path[30] = "visual/img/numbers/0.xpm";

	path[19] = n;
	return (path);
}

void	init_numbers(t_env *v)
{
	int		x;
	int		y;

	x = 20;
	y = 25;
	v->mlx.ze = mlx_xpm_file_to_image(v->mlx.ptr, ret_path('0'), &x, &y);
	v->mlx.on = mlx_xpm_file_to_image(v->mlx.ptr, ret_path('1'), &x, &y);
	v->mlx.tw = mlx_xpm_file_to_image(v->mlx.ptr, ret_path('2'), &x, &y);
	v->mlx.th = mlx_xpm_file_to_image(v->mlx.ptr, ret_path('3'), &x, &y);
	v->mlx.fo = mlx_xpm_file_to_image(v->mlx.ptr, ret_path('4'), &x, &y);
	v->mlx.fi = mlx_xpm_file_to_image(v->mlx.ptr, ret_path('5'), &x, &y);
	v->mlx.si = mlx_xpm_file_to_image(v->mlx.ptr, ret_path('6'), &x, &y);
	v->mlx.se = mlx_xpm_file_to_image(v->mlx.ptr, ret_path('7'), &x, &y);
	v->mlx.ei = mlx_xpm_file_to_image(v->mlx.ptr, ret_path('8'), &x, &y);
	v->mlx.ni = mlx_xpm_file_to_image(v->mlx.ptr, ret_path('9'), &x, &y);
	if (!v->mlx.ze || !v->mlx.on || !v->mlx.tw || !v->mlx.th || !v->mlx.fo ||
			!v->mlx.fi || !v->mlx.si || !v->mlx.se || !v->mlx.ei || !v->mlx.ni)
		ft_print_error("Number file missing.\n");
}

void	start_mlx(t_env *v)
{
	v->mlx.ptr = mlx_init();
	create_win(v);
	init_numbers(v);
	create_map(v);
	clear_map(v);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:26:45 by agouby            #+#    #+#             */
/*   Updated: 2017/09/25 22:01:00 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	print_nb(t_env *v, int n, int x, int y)
{
	static int i = 0;

	if (n > 9)
	{
		print_nb(v, n / 10, x, y);
		i++;
	}
	print_char(v, n % 10 + 48, x + i * 20, y);
	i = 0;
}

void	print_char(t_env *v, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.ze, x, y);
	else if (c == '1')
		mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.on, x, y);
	else if (c == '2')
		mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.tw, x, y);
	else if (c == '3')
		mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.th, x, y);
	else if (c == '4')
		mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.fo, x, y);
	else if (c == '5')
		mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.fi, x, y);
	else if (c == '6')
		mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.si, x, y);
	else if (c == '7')
		mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.se, x, y);
	else if (c == '8')
		mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.ei, x, y);
	else if (c == '9')
		mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.ni, x, y);
}

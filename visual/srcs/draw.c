/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 22:14:10 by agouby            #+#    #+#             */
/*   Updated: 2017/09/20 22:38:46 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		draw_point(t_env *v, t_coord p, int color)
{
	int i;

	if ((int)p.x < 0 || (int)p.x >= WIDTH || (int)p.y < 0 || (int)p.y >= HEIGHT)
		return ;
	i = ((int)p.x * 4) + ((int)p.y * v->s_line);
	v->pixel_img[i] = color;
	v->pixel_img[++i] = color >> 8;
	v->pixel_img[++i] = color >> 16;
}

t_bres	draw_line_set(t_coord p1, t_coord p2)
{
	t_bres bres;

	bres.dx = abs((int)p2.x - (int)p1.x);
	bres.dy = abs((int)p2.y - (int)p1.y);
	if ((int)p1.x < (int)p2.x)
		bres.sx = 1;
	else
		bres.sx = -1;
	if ((int)p1.y < (int)p2.y)
		bres.sy = 1;
	else
		bres.sy = -1;
	bres.err = bres.dx - bres.dy;
	return (bres);
}

void	draw_line(t_env *v, t_coord p1, t_coord p2)
{
	t_bres bres;

	bres = draw_line_set(p1, p2);
	while (!((int)p1.x == (int)p2.x && (int)p1.y == (int)p2.y))
	{
		draw_point(v, p1, LN_CLR);
		bres.e2 = 2 * bres.err;
		if (bres.e2 > -bres.dy)
		{
			bres.err = bres.err - bres.dy;
			p1.x = (int)p1.x + bres.sx;
		}
		if (bres.e2 < bres.dx)
		{
			bres.err = bres.err + bres.dx;
			p1.y = (int)p1.y + bres.sy;
		}
	}
	draw_point(v, p1, LN_CLR);
}


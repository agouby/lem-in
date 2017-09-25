/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:17:16 by agouby            #+#    #+#             */
/*   Updated: 2017/09/25 21:19:37 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_limits(t_limit *x, t_limit *y)
{
	x->min = -1;
	x->max = -1;
	y->min = -1;
	y->max = -1;
}

void	get_limits(t_room *r, t_limit *x, t_limit *y)
{
	if (x->min == -1 || (long)r->x < x->min)
		x->min = r->x;
	if (x->max == -1 || (long)r->x > x->max)
		x->max = r->x;
	if (y->min == -1 || (long)r->y < y->min)
		y->min = r->y;
	if (y->max == -1 || (long)r->y > y->max)
		y->max = r->y;
}

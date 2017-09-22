/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:01:48 by agouby            #+#    #+#             */
/*   Updated: 2017/09/20 17:02:34 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	print_map(t_env *v)
{
	(void)v;
}

void	clear_img(t_env *v)
{
	t_coord	i;

	i.y = 0;
	while (i.y < MAP_Y + OFFSET * 2)
	{
		i.x = 0;
		while (i.x < MAP_X + OFFSET * 2)
		{
			draw_point(v, i, 0x181818);
			i.x++;
		}
		i.y++;
	}
}

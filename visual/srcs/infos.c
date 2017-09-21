/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:34:18 by agouby            #+#    #+#             */
/*   Updated: 2017/09/21 22:40:01 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

#include <stdio.h>

void	get_connexions(t_env *v, char *line)
{
	char	*tmp;
	t_room	*prev;
	t_room	*cur;

	tmp	= line;
	prev = NULL;
	cur = NULL;
	while (tmp)
	{
		prev = cur;
		tmp = get_room(v, tmp, &cur);
		if (prev)
			draw_line(v, prev->c, cur->c);
	}
}

void	get_limits(t_env *v, char *line)
{
	char	*ptr;

	ptr = ft_strchr(line, ' ');
	v->x.min = ft_atou(line);
	line = ptr;
	line++;
	ptr = ft_strchr(line, ' ');
	v->x.max = ft_atou(line);
	line = ptr;
	line++;
	ptr = ft_strchr(line, ' ');
	v->y.min = ft_atou(line);
	line = ptr;
	v->y.max = ft_atou(line);
//	ft_printf("X MIN = %d, X MAX = %d, Y MIN = %d, Y MAX = %d\n",
//			v->x.min, v->x.max, v->y.min, v->y.max);
	if ((v->dist.x = v->x.max - v->x.min))
		v->fac_x = (float)MAP_X / (float)v->dist.x;
	if ((v->dist.y = v->y.max - v->y.min))
		v->fac_y = (float)MAP_Y / (float)v->dist.y;
	ft_printf("%d, %d\n", v->dist.x, v->dist.y);
	printf("%f, %f\n", v->fac_x, v->fac_y);
}

void	get_infos(t_env *v)
{
	t_list	*tmp;

	tmp = v->file;
	get_limits(v, tmp->content);
	tmp = tmp->next;
	while (tmp && !ft_strequ(tmp->content, "SOLUTION"))
	{
		get_connexions(v, tmp->content);
		tmp = tmp->next;
	}
	//	print_list(v->list);
}

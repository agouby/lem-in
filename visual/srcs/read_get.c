/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:16:23 by agouby            #+#    #+#             */
/*   Updated: 2017/09/23 01:36:58 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

char	check_exist(t_rlist *list, char *line)
{
	t_rlist *tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strequ(line, tmp->r->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

char	*get_room(t_env *v, char *line, t_room **r)
{
	char	*ptr;

	ptr = ft_strchr(line, ' ');
	*ptr = '\0';
	(*r) = (t_room *)malloc(sizeof(t_room));
	(*r)->name = ft_strdup(line);
	(*r)->has_ant = 0;
	ptr++;
	(*r)->c.x = ft_atou(ptr);
	while (ft_isdigit(*ptr))
		ptr++;
	ptr++;
	(*r)->c.y = ft_atou(ptr);
	while (ft_isdigit(*ptr))
		ptr++;
	if (!check_exist(v->list, line))
		rlist_add(&v->list, rlist_new(*r));
	(*r)->c.x = (*r)->c.x - v->x.min;
	(*r)->c.y = (*r)->c.y - v->y.min;
	(*r)->c.x *= v->fac_x;
	(*r)->c.y *= v->fac_y;
	(*r)->c.x += OFFSET;
	(*r)->c.y += OFFSET;
	return ((*ptr) ? ptr + 1 : NULL);
}

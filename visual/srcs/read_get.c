/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:16:23 by agouby            #+#    #+#             */
/*   Updated: 2017/09/25 21:26:34 by agouby           ###   ########.fr       */
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

void	calc_coords(t_env *v, long *x, long *y)
{
	*x = *x - v->x.min;
	*y = *y - v->y.min;
	*x *= v->fac_x;
	*y *= v->fac_y;
	*x += OFFSET;
	*y += OFFSET;
}

char	*get_room(t_env *v, char *line, t_room **r)
{
	char	*ptr;

	if (!(ptr = ft_strchr(line, ' ')))
		ft_print_error("File is corrupted.\n");
	*ptr = '\0';
	if (!*line)
		ft_print_error("File is corrupted.\n");
	(*r)->name = ft_strdup(line);
	ptr++;
	if (*ptr == '-')
		ft_print_error("Error coordinates.\n");
	(*r)->c.x = ft_atou(ptr);
	while (ft_isdigit(*ptr))
		ptr++;
	ptr++;
	if (*ptr == '-')
		ft_print_error("Error coordinates.\n");
	(*r)->c.y = ft_atou(ptr);
	while (ft_isdigit(*ptr))
		ptr++;
	calc_coords(v, &(*r)->c.x, &(*r)->c.y);
	return ((*ptr) ? ptr + 1 : NULL);
}

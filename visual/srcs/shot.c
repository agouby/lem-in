/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 02:00:22 by agouby            #+#    #+#             */
/*   Updated: 2017/09/23 02:12:47 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	write_ant_in_room(t_env *v, char *line)
{
	t_rlist	*tmp;

	tmp = v->list;
	while (tmp)
	{
		if (ft_strequ(tmp->r->name, line))
			tmp->r->has_ant = 1;
		tmp = tmp->next;
	}
}

void	mark_room(t_env *v)
{
	char	*line;
	char	*ptr;

	line = v->sol[v->cur_shot];
	ptr = ft_strchr(line, '-');
	if (!ptr)
		ft_print_error("File is corrupted.\n");
	ptr++;
	line = ptr;
	ptr = ft_strchr(line, ' ');
	*ptr = '\0';
	write_ant_in_room(v, line);
	ptr = ft_strchr(line, '-');
	if (!ptr)
		ft_print_error("File is corrupted.\n");
	ptr++;
	write_ant_in_room(v, ptr);
}

void	print_shot(t_env *v)
{
	mark_room(v);
}

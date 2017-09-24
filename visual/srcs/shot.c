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

void	clear_rooms(t_env *v)
{
	t_rlist	*tmp;

	tmp = v->list;
	while (tmp)
	{
		if (!ft_strequ(tmp->r->name, v->start.name) && !ft_strequ(tmp->r->name, v->end.name))
			mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.room_f,
				tmp->r->c.x + 45 - 25, tmp->r->c.y + 45 - 25);
		tmp = tmp->next;
	}
}

void	write_ant_in_room(t_env *v, char *line)
{
	t_rlist	*tmp;

	tmp = v->list;
	while (v->list)
	{
		if (ft_strequ(v->list->r->name, v->end.name))
			;
		else if (ft_strequ(v->list->r->name, line))
		{
			mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.room_t,
				v->list->r->c.x + 45 - 25, v->list->r->c.y + 45 - 25);
		}
		v->list = v->list->next;
	}
	v->list = tmp;
}

void	print_shot(t_env *v)
{
	char	*line;
	char	*ptr;
	size_t	cnt;

	clear_rooms(v);
	if (v->cur_shot == -1)
		return ;
	line = v->sol[v->cur_shot];
	cnt = 0;
	while (1)
	{
		if (!v->nb_paths)
			cnt++;
		line = ft_strchr(line, '-');
		if (!line)
			return ;
		line++;
		ptr = ft_strchr(line, ' ');
		*ptr = '\0';
		write_ant_in_room(v, line);
		*ptr = ' ';
		ptr++;
	}
	v->nb_paths = cnt;
}

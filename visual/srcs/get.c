/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:32:15 by agouby            #+#    #+#             */
/*   Updated: 2017/09/25 21:42:22 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	get_connexions(t_env *v, char *line)
{
	t_room	*cur;
	t_coord	tmp_c;

	cur = NULL;
	while (line)
	{
		cur = (t_room *)malloc(sizeof(t_room));
		if (!(line = get_room(v, line, &cur)))
			draw_line(v, tmp_c, cur->c);
		tmp_c = cur->c;
		if (!check_exist(v->list, cur->name))
		{
			rlist_add(&v->list, rlist_new(cur));
			v->nb_rooms++;
		}
		else
		{
			ft_strdel(&cur->name);
			ft_memdel((void **)&cur);
		}
	}
}

void	get_limits(t_env *v, char *line)
{
	char	*ptr;

	ptr = ft_strchr(line, ' ');
	if (!ptr)
		ft_print_error("File is corrupted.\n");
	v->x.min = ft_atou(line);
	line = ptr;
	line++;
	ptr = ft_strchr(line, ' ');
	v->x.max = ft_atou(line);
	line = ptr;
	if (!line)
		ft_print_error("File is corrupted.\n");
	line++;
	ptr = ft_strchr(line, ' ');
	v->y.min = ft_atou(line);
	line = ptr;
	v->y.max = ft_atou(line);
	if ((v->dist.x = v->x.max - v->x.min))
		v->fac_x = (float)MAP_X / (float)v->dist.x;
	if ((v->dist.y = v->y.max - v->y.min))
		v->fac_y = (float)MAP_Y / (float)v->dist.y;
}

void	get_start_and_end(t_env *v, char *line)
{
	char *ptr;

	ptr = ft_strchr(line, ' ');
	if (!ptr)
	{
		ft_lstdel(&v->file, del_file);
		ft_print_error("File is corrupted.\n");
	}
	*ptr = '\0';
	ptr++;
	v->start.name = line;
	v->end.name = ptr;
}

void	get_sol_tab(t_env *v, t_list *list)
{
	size_t	i;
	char	*ptr;

	i = 0;
	v->sol = (char **)malloc(sizeof(char *) * (v->nb_shots + 1));
	while (i < v->nb_shots)
	{
		v->sol[i] = list->content;
		list = list->next;
		i++;
	}
	if (i == 1)
		v->direct = 1;
	ptr = v->sol[0];
	while ((ptr = ft_strchr(ptr, ' ')))
	{
		ptr++;
		v->nb_paths++;
	}
	v->sol[i] = NULL;
}

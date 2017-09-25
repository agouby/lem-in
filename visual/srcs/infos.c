/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:34:18 by agouby            #+#    #+#             */
/*   Updated: 2017/09/23 02:11:58 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

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
		cur = (t_room *)malloc(sizeof(t_room));
		tmp = get_room(v, tmp, &cur);
		if (prev)
			draw_line(v, prev->c, cur->c);
		if (!check_exist(v->list, tmp))
			rlist_add(&v->list, rlist_new(cur));
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
	v->sol[i] = NULL;
}

void	get_infos(t_env *v)
{
	t_list	*tmp;

	tmp = v->file;
	if (!ft_strisdigit(tmp->content))
	{
		ft_lstdel(&v->file, del_file);
		ft_print_error("File is corrupted.\n");
	}
	v->nb_ants = ft_atou(tmp->content);
	tmp = tmp->next;
	get_limits(v, tmp->content);
	tmp = tmp->next;
	get_start_and_end(v, tmp->content);
	tmp = tmp->next;
	start_mlx(v);
	print_back(v);
	while (tmp && !ft_strequ(tmp->content, "SOLUTION"))
	{
		get_connexions(v, tmp->content);
		tmp = tmp->next;
	}
	if (!tmp)
	{
		del_mlx(v);
		ft_print_error("File is corrupted.\n");
	}
	print_map(v);
	tmp = tmp->next;
	v->nb_shots = ft_lstlen(tmp);
	get_sol_tab(v, tmp);
	print_shot(v);
}

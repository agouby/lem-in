/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:54:49 by agouby            #+#    #+#             */
/*   Updated: 2017/09/20 14:09:52 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	score_map(t_env *lem)
{
	t_rlist *cur;

	cur = lem->end;
	cur->r->score = 0;
	rlist_add(&lem->queue, rlist_new(cur->r));
	while (lem->queue && !lem->start_fnd)
	{
		write_nei_in_queue(lem, cur->r);
		cur = del_last_queue(&lem->queue);
	}
	del_queue(&lem->queue);
}

void	rebuild_path(t_env *lem)
{
	t_rlist *cur;
	t_rlist	*new;

	new = NULL;
	cur = lem->start;
	lem->end->r->score = 0;
	path_add(&lem->paths, path_new(new));
	lem->paths->lst = NULL;
	rlist_add(&lem->paths->lst, rlist_new(cur->r));
	while (cur->r != lem->end->r)
	{
		cur = get_next_room(lem, cur->r);
		rlist_add(&lem->paths->lst, rlist_new(cur->r));
	}
}

void	get_paths(t_env *lem)
{
	unsigned int	max_path;

	if (!lem->start || !lem->end)
		quit_parsing(lem);
	max_path = get_start_nei(lem->start);
	if (lem->args.max_path && (lem->args.max_path < max_path))
		max_path = lem->args.max_path;
	if ((lem->direct = is_in_list(lem->start->r->nei, lem->end->r->name)))
		return ;
	while (max_path)
	{
		lem->start_fnd = 0;
		score_map(lem);
		if (!lem->start_fnd)
			break ;
		max_path--;
		rebuild_path(lem);
		init_al_vis(lem->hash);
	}
	if (!lem->paths)
		quit_path(lem);
	lem->paths = path_rev(lem->paths);
}

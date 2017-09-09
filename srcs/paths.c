/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:54:49 by agouby            #+#    #+#             */
/*   Updated: 2017/09/09 21:33:33 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_queue(t_rlist *queue)
{
	ft_printf("PRINTING QUEUE \n\n");
	while (queue)
	{
		ft_printf("%s, %d, %d\n", queue->r->name, queue->r->score, queue->r->al_vis);
		queue = queue->next;
	}
	ft_printf("\n");
}

void	print_path(t_env *lem)
{
	ft_printf("PRINTING PATH \n\n");
	while (lem->paths)
	{
		ft_printf("%s", lem->paths->r->name);
		if (lem->paths->next)
			ft_printf(" - ");
		lem->paths = lem->paths->next;
	}
	ft_printf("\n");
}

int		alrdy_in_queue(char *name, t_rlist *queue)
{
	while (queue)
	{
		if (ft_strequ(queue->r->name, name))
			return (1);
		queue = queue->next;
	}
	return (0);
}

void	write_nei_in_queue(t_env *lem, t_room *r)
{
	t_room *tmp;

	tmp = r;
//	ft_printf("FOR %s :\n", r->name);
	while (tmp->nei)
	{
		if (!tmp->nei->r->al_vis)
		{
//			ft_printf("\t%s\n", tmp->nei->r->name);
			tmp->nei->r->score = r->score + 1;
			tmp->nei->r->al_vis = 1;
			if (ft_strequ(tmp->nei->r->name, lem->start->r->name))
				lem->start_fnd = 1;
			rlist_add(&lem->queue, rlist_newalloc(tmp->nei->r));
		}
		tmp->nei = tmp->nei->next;
	}
//	tmp->al_vis = 1;
}

t_rlist	*get_last(t_rlist *queue)
{
	t_rlist *tmp;

	tmp = queue;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	score_map(t_env *lem)
{
	t_rlist *cur;

	int i = 0;

	cur = lem->end;
	cur->r->score = 0;
	rlist_add(&lem->queue, rlist_new(cur->r));
//	print_queue(lem->queue);
	while (lem->queue && !lem->start_fnd)
	{
//		ft_printf("%s\n", cur->r->name);
		write_nei_in_queue(lem, cur->r);
//		lem->queue = lem->queue->next;	
//		print_queue(lem->queue);
		del_last_queue(&lem->queue);
//		lem->queue = lem->queue->next;
		cur = get_last(lem->queue);
//		ft_printf("NEW = %s\n", cur->r->name);
		i++;
	}
}

t_rlist 	*get_next_room(t_room *cur)
{
	ssize_t	i;
	t_rlist	*ret;
	t_rlist	*tmp;

	i = 99999;
	ret = cur->nei;
	tmp = cur->nei;
	while (tmp)
	{
		if (tmp->r->score != -1 && tmp->r->score < i)
		{
			i = tmp->r->score;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	return (ret);
}

void	rebuild_path(t_env *lem)
{
	t_rlist *cur;

	cur = lem->start;
	lem->end->r->score = 0;
	rlist_add(&lem->paths, rlist_new(cur->r));
	while (cur->r != lem->end->r)
	{
		cur = get_next_room(cur->r);
		ft_printf("%s, %d\n", cur->r->name, cur->r->score);
//		ft_printf("%s\n", cur->r->name);
		rlist_add(&lem->paths, rlist_new(cur->r));
	}
	print_path(lem);
}

void	get_paths(t_env *lem)
{
	score_map(lem);
	rebuild_path(lem);
}

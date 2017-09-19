/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 23:16:29 by agouby            #+#    #+#             */
/*   Updated: 2017/09/19 23:17:25 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	t_room	*tmp;
	t_rlist	*nei_tmp;

	tmp = r;
	nei_tmp = tmp->nei;
	while (nei_tmp)
	{
		if (!nei_tmp->r->al_vis && !nei_tmp->r->banned)
		{
			nei_tmp->r->score = r->score + 1;
			nei_tmp->r->al_vis = 1;
			if (ft_strequ(nei_tmp->r->name, lem->start->r->name))
				lem->start_fnd = 1;
			rlist_add(&lem->queue, rlist_new(nei_tmp->r));
		}
		nei_tmp = nei_tmp->next;
	}
}

void	del_queue(t_rlist **queue)
{
	t_rlist *tmp;

	while (*queue)
	{
		tmp = *queue;
		*queue = (*queue)->next;
		free(tmp);
	}
	queue = NULL;
}

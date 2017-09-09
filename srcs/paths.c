/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:54:49 by agouby            #+#    #+#             */
/*   Updated: 2017/09/09 16:25:06 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_queue(t_env lem)
{
	ft_printf("PRINTING QUEUE \n\n");
	while (lem.queue)
	{
		ft_printf("%s, %d\n", lem.queue->r.name, lem.queue->r.al_vis);
		lem.queue = lem.queue->next;
	}
	ft_printf("\n");
}

void	write_nei_in_queue(t_env *lem, t_room *r)
{
	t_room *tmp;

	tmp = r;
	while (tmp->nei)
	{
		ft_printf("%s, %d\n", tmp->nei->r.name, tmp->nei->r.al_vis);
		if (!tmp->nei->r.al_vis)
		{
			rlist_add(&lem->queue, rlist_new(tmp->nei->r));
		}
		tmp->nei = tmp->nei->next;
	}
}

void	get_paths(t_env *lem)
{
	t_rlist *cur;
	int	*lol;

	int i = 0;

	cur = lem->end->r.nei;
	lol = &cur->r.al_vis;
	while (i < 2)
	{
		write_nei_in_queue(lem, &cur->r);
		print_queue(*lem);
		cur->r.al_vis = 1;
//		ft_printf("NAME = %s\n", cur->r.name);
//		ft_printf("AL_VIS = %d\n", cur->r.al_vis);
		cur = lem->queue;
//		ft_printf("NAME = %s\n", cur->r.name);
//		ft_printf("AL_VIS = %d\n", cur->r.al_vis);
		i++;
	}
}

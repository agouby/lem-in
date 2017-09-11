/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:54:49 by agouby            #+#    #+#             */
/*   Updated: 2017/09/11 20:41:38 by agouby           ###   ########.fr       */
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
	ft_printf("\n\n");
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
			rlist_add(&lem->queue, rlist_newalloc(nei_tmp->r));
		}
		nei_tmp = nei_tmp->next;
	}
}

void	del_queue(t_rlist **queue)
{
	t_rlist *tmp;

	while (*queue)
	{
		tmp = (*queue)->next;
		free(*queue);
		*queue = tmp;
	}
	*queue = NULL;
}

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

void		init_al_vis(t_rlist **hash)
{
	size_t	i;
	t_rlist *tmp;
	
	i = 0;
	while (i < H_SIZE)
	{
		tmp = hash[i];
		if (hash[i])
		{
			while (tmp)
			{
				tmp->r->al_vis = 0;
				tmp->r->score = -1;
				tmp = tmp->next;
			}
			hash[i]->r->score = -1;
			hash[i]->r->al_vis = 0;
		}
		i++;
	}
}

t_rlist 	*get_next_room(t_env *lem, t_room *cur)
{
	ssize_t	i;
	t_rlist	*ret;
	t_rlist	*tmp;

	i = -1;
	ret = cur->nei;
	tmp = cur->nei;
	while (tmp)
	{
		if (tmp->r->score != -1 && (tmp->r->score < i || i == -1))
		{
			i = tmp->r->score;
			ret = tmp;
		}
		tmp = tmp->next;
	}
	if (ret->r != lem->end->r)
	   ret->r->banned = 1;
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
		cur = get_next_room(lem, cur->r);
		rlist_add(&lem->paths, rlist_new(cur->r));
	}
	print_path(lem);
}

void	get_paths(t_env *lem)
{
	while (1)
	{
		lem->start_fnd = 0;
		score_map(lem);
		if (!lem->start_fnd)
			ft_print_error("END OF PATHS");
		rebuild_path(lem);
		init_al_vis(lem->hash);
	}
}

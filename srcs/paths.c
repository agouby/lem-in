/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:54:49 by agouby            #+#    #+#             */
/*   Updated: 2017/09/11 21:48:12 by agouby           ###   ########.fr       */
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
		ft_printf("%s", lem->paths->content);
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
	while (*queue)
	{
		free(*queue);
		*queue = NULL;
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
	ft_lstadd(&lem->paths, ft_lstnew_noalloc(cur->r->name));
	while (cur->r != lem->end->r)
	{
		cur = get_next_room(lem, cur->r);
		ft_lstadd(&lem->paths, ft_lstnew_noalloc(cur->r->name));
	}
	print_path(lem);
}

unsigned char is_in_list(t_rlist *list, char *str)
{
	while (list)
	{
		if (ft_strequ(list->r->name, str))
			return (1);
		list = list->next;
	}
	return (0);
}

size_t	get_start_nei(t_rlist *start)
{
	t_rlist *tmp;
	size_t	i;

	tmp = start->r->nei;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	check_direct_map(t_env *lem)
{
	lem->direct = is_in_list(lem->start->r->nei, lem->end->r->name);
}

void	get_paths(t_env *lem)
{

	int max_path;


	max_path = get_start_nei(lem->start);
	check_direct_map(lem);
	if (lem->direct)
		return ;
	while (max_path)
	{
		lem->start_fnd = 0;
		score_map(lem);
		if (!lem->start_fnd)
		{
			ft_printf("END OF PATHS\n");
			return ;
		}
		max_path--;
		rebuild_path(lem);
		init_al_vis(lem->hash);
	}
}

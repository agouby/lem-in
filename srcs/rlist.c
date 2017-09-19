/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:43:43 by agouby            #+#    #+#             */
/*   Updated: 2017/09/11 21:43:18 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		rlist_add(t_rlist **old, t_rlist *new)
{
	new->next = *old;
	*old = new;
}

t_rlist		*rlist_new(t_room *r)
{
	t_rlist *new;

	new = (t_rlist *)malloc(sizeof(t_rlist));
	new->r = r;
	new->next = NULL;
	return (new);
}

t_rlist		*rlist_newalloc(t_room *r)
{
	t_rlist *new;

	new = (t_rlist *)malloc(sizeof(t_rlist));
	new->r = (t_room *)malloc(sizeof(t_room));
	ft_memcpy(new->r, r, sizeof(t_room));
	new->next = NULL;
	return (new);
}

t_rlist		*del_last_queue(t_rlist **queue)
{
	t_rlist *tmp;
	t_rlist *prev;

	tmp = *queue;
	if (!tmp->next)
	{
		free(*queue);
		*queue = NULL;
		return (NULL);
	}
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	free(prev->next);
	prev->next = NULL;
	return (prev);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:24:32 by agouby            #+#    #+#             */
/*   Updated: 2017/09/25 21:20:40 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

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

void		rlist_addb(t_rlist **old, t_rlist *new)
{
	t_rlist *tmp;

	if (*old == NULL)
	{
		*old = new;
		return ;
	}
	tmp = *old;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

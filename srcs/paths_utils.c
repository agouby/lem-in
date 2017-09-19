/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 23:19:58 by agouby            #+#    #+#             */
/*   Updated: 2017/09/19 23:23:29 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			init_al_vis(t_rlist **hash)
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

t_rlist			*get_next_room(t_env *lem, t_room *cur)
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

unsigned char	is_in_list(t_rlist *list, char *str)
{
	while (list)
	{
		if (ft_strequ(list->r->name, str))
			return (1);
		list = list->next;
	}
	return (0);
}

size_t			get_start_nei(t_rlist *start)
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

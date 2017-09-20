/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:34:11 by agouby            #+#    #+#             */
/*   Updated: 2017/09/20 10:03:30 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_hash_slot(t_rlist **hash, size_t i)
{
	t_rlist	*tmp;
	t_rlist	*tmp_nei;

	while (hash[i])
	{
		tmp = hash[i];
		hash[i] = hash[i]->next;
		while (tmp->r->nei)
		{
			tmp_nei = tmp->r->nei;
			tmp->r->nei = tmp->r->nei->next;
			free(tmp_nei);
		}
		free(tmp->r->name);
		free(tmp->r);
		free(tmp);
	}
}

void	del_hash(t_rlist **hash)
{
	size_t i;

	i = 0;
	while (i < H_SIZE)
	{
		free_hash_slot(hash, i);
		i++;
	}
	free(hash);
}

void	del_paths(t_path *paths)
{
	t_path	*tmp_path;
	t_rlist	*tmp_lst;

	while (paths)
	{
		tmp_path = paths->next;
		while (paths->lst)
		{
			tmp_lst = paths->lst->next;
			free(paths->lst);
			paths->lst = tmp_lst;
		}
		free(paths);
		paths = tmp_path;
	}
}

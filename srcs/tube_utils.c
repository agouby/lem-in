/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:33:58 by agouby            #+#    #+#             */
/*   Updated: 2017/09/07 21:04:38 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	push_tube_in_room(t_env *lem, char *cur, char *nei, size_t hash)
{
	t_rlist	*tmp;
	t_list	*tmp_nei;

	tmp = lem->hash[hash];
	while (tmp && !ft_strequ(tmp->r.name, cur))
		tmp = tmp->next;
	tmp_nei = tmp->r.nei;
	while (tmp_nei)
	{
		if (ft_strequ(tmp_nei->content, nei))
			return ;
		tmp_nei = tmp_nei->next;
	}
	ft_lstadd(&tmp->r.nei, ft_lstnew(nei, ft_strlen(nei) + 1));
}

void	convert_tube(t_env *lem, char *line, size_t cut)
{
	size_t	hash;
	size_t	hash_sec;

	line[cut] = '\0';
	hash = get_hash_index(line);
	hash_sec = get_hash_index(line + cut + 1);
	if (!lem->hash[hash] || !lem->hash[hash_sec])
	{
		ft_printf("Error tube : Room doesn't exist.\n");
		line[cut] = '-';
		return ;
	}
	push_tube_in_room(lem, line, line + cut + 1, hash);
	push_tube_in_room(lem, line + cut + 1, line, hash_sec);
	line[cut] = '-';
}

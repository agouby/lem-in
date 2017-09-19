/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:32:43 by agouby            #+#    #+#             */
/*   Updated: 2017/09/19 22:33:27 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	coll(t_rlist *tmp)
{
	t_rlist *tmp_nei;

	while (tmp)
	{
		ft_printf("%s (%d, %d)\n\t", tmp->r->name, tmp->r->x, tmp->r->y);
		if (!(tmp_nei = tmp->r->nei))
		{
			ft_printf("No neighbours\n");
			break ;
		}
		while (tmp_nei->next)
		{
			ft_printf("%s-", tmp_nei->r->name);
			tmp_nei = tmp_nei->next;
		}
		ft_printf("%s\n", tmp_nei->r->name);
		tmp = tmp->next;
	}
}

void	print_hash(t_env *lem)
{
	size_t	i;
	t_rlist *tmp;

	i = 0;
	ft_printf("** PRINTING HASH **\n\n");
	while (i < H_SIZE)
	{
		if (lem->hash[i])
		{
			tmp = lem->hash[i];
			coll(tmp);
		}
		i++;
	}
	ft_printf("\n");
}

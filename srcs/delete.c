/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:57:16 by agouby            #+#    #+#             */
/*   Updated: 2017/09/11 17:45:28 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_hash(t_env *lem)
{
	size_t	i;
	t_rlist *tmp;
	t_rlist *tmp_nei;

	i = 0;
	ft_printf("PRINTING INFOS :\n\n");
	while (i < H_SIZE)
	{
		if (lem->hash[i])
		{
			tmp = lem->hash[i];
			while (tmp)
			{
				ft_printf("%s (%d, %d) BANNED : %d AL_VIS : %d\n", tmp->r->name,
						tmp->r->x, tmp->r->y, tmp->r->banned, tmp->r->al_vis);
				tmp_nei = tmp->r->nei;
				while (tmp_nei)
				{
					ft_printf("    %s\n", tmp_nei->r->name);
					tmp_nei = tmp_nei->next;
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
	ft_printf("\n");
}

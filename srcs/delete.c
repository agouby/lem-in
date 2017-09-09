/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:57:16 by agouby            #+#    #+#             */
/*   Updated: 2017/09/09 16:28:49 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_hash(t_env *lem)
{
	size_t	i;

	i = 0;
	ft_printf("PRINTING INFOS :\n\n");
	while (i < H_SIZE)
	{
		if (lem->hash[i])
		{
			while (lem->hash[i])
			{
				ft_printf("%s (%d, %d)\n", lem->hash[i]->r->name,
						lem->hash[i]->r->x, lem->hash[i]->r->y);
				while (lem->hash[i]->r->nei)
				{
					ft_printf("    %s\n", lem->hash[i]->r->nei->r->name);
					lem->hash[i]->r->nei = lem->hash[i]->r->nei->next;
				}
				lem->hash[i] = lem->hash[i]->next;
			}
		}
		i++;
	}
	ft_printf("\n");
}

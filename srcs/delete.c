/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:57:16 by agouby            #+#    #+#             */
/*   Updated: 2017/09/07 18:59:28 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_hash(t_env *lem)
{
	size_t	i;

	i = 0;
	(void)lem;
	while (i < H_SIZE)
	{
		if (lem->hash[i])
		{
			while (lem->hash[i])
			{
				ft_printf("%s\n", lem->hash[i]->r.name);
				while (lem->hash[i]->r.nei)
				{
					ft_printf("    %s\n", lem->hash[i]->r.nei->content);
					lem->hash[i]->r.nei = lem->hash[i]->r.nei->next;
				}
				lem->hash[i] = lem->hash[i]->next;
			}
		}
		i++;
	}
}

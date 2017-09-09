/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:20:42 by agouby            #+#    #+#             */
/*   Updated: 2017/09/07 21:57:11 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print(t_env *lem)
{
	size_t i = 0;


	ft_printf("START : \n\n");
	while (lem->start->r.nei)
	{
		ft_printf("%s\n", lem->start->r.nei->content);
		lem->start->r.nei = lem->start->r.nei->next;
		i++;
	}
	ft_printf("%d\n", i);
	i = 0;
	ft_printf("\nEND : \n\n");
	while (lem->end->r.nei)
	{
		ft_printf("%s\n", lem->end->r.nei->content);
		lem->end->r.nei = lem->end->r.nei->next;
		i++;
	}
	ft_printf("%d\n", i);
}

int		main(void)
{
	t_env	lem;

	ft_memset(&lem, 0, sizeof(lem));
	parse_map(&lem);
//	print_hash(&lem);
	print(&lem);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:11:58 by agouby            #+#    #+#             */
/*   Updated: 2017/09/19 23:16:59 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_file(t_env lem)
{
	lem.file = ft_lstrev(lem.file);
	ft_printf("PRINTING FILE : \n\n");
	while (lem.file)
	{
		ft_printf("%s\n", lem.file->content);
		lem.file = lem.file->next;
	}
}

void	print_paths(t_env *lem)
{
	ft_printf("PRINTING PATH \n\n");
	while (lem->paths)
	{
		while (lem->paths->lst)
		{
			ft_printf("%s", lem->paths->lst->r->name);
			if (lem->paths->lst->next)
				ft_printf(" - ");
			lem->paths->lst = lem->paths->lst->next;
		}
		ft_printf("\n");
		lem->paths = lem->paths->next;
	}
	ft_printf("\n\n");
}

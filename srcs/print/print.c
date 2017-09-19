/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:11:58 by agouby            #+#    #+#             */
/*   Updated: 2017/09/19 23:58:53 by agouby           ###   ########.fr       */
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
	ft_printf("\n");
}

void	print_paths(t_env lem)
{
	t_path	*tmp;
	t_rlist	*tmp_lst;

	ft_printf("PRINTING PATH \n\n");
	tmp = lem.paths;
	while (tmp)
	{
		tmp_lst = tmp->lst;
		while (tmp_lst)
		{
			ft_printf("%s", tmp_lst->r->name);
			if (tmp_lst->next)
				ft_printf(" - ");
			tmp_lst = tmp_lst->next;
		}
		ft_printf("\n");
		tmp = tmp->next;
	}
	ft_printf("\n");
}

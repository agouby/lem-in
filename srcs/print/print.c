/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:11:58 by agouby            #+#    #+#             */
/*   Updated: 2017/09/21 16:11:18 by agouby           ###   ########.fr       */
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

void	lst_rev(t_rlist **lst)
{
	t_rlist	*new;
	t_rlist	*elem;

	new = NULL;
	while (*lst)
	{
		elem = *lst;
		*lst = (*lst)->next;
		elem->next = new;
		new = elem;
	}
	*lst = new;
}

void	print_paths(t_env lem)
{
	t_path	*tmp;
	t_rlist	*tmp_lst;
	size_t	i;

	ft_printf("PRINTING PATH \n\n");
	tmp = lem.paths;
	while (tmp)
	{
		lst_rev(&tmp->lst);
		tmp_lst = tmp->lst;
		i = 0;
		while (tmp_lst)
		{
			ft_printf("%s", tmp_lst->r->name);
			if (tmp_lst->next)
				ft_printf(" - ");
			tmp_lst = tmp_lst->next;
			i++;
		}
		lst_rev(&tmp->lst);
		ft_printf("     Path len = %d\n", i);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	print_visual_infos(t_env lem)
{
	t_path	*tmp;
	t_rlist *tmp_lst;

	tmp = lem.paths;
	ft_dprintf(lem.args.v_fd, "%s %d %d %s %d %d\n",
			lem.start->r->name, lem.start->r->x, lem.start->r->y,
			lem.end->r->name, lem.end->r->x, lem.end->r->y);
	while (tmp)
	{
		tmp_lst = tmp->lst->next;
		while (tmp_lst->next)
		{
			ft_dprintf(lem.args.v_fd, "%s %d %d",
					tmp_lst->r->name, tmp_lst->r->x, tmp_lst->r->y);
			if (tmp_lst->next->next)
				ft_dprintf(lem.args.v_fd, " ");
			tmp_lst = tmp_lst->next;
		}
		ft_dprintf(lem.args.v_fd, "\n");
		tmp = tmp->next;
	}
}

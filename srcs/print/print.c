/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:11:58 by agouby            #+#    #+#             */
/*   Updated: 2017/09/25 22:17:06 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_file(t_env lem)
{
	t_list *tmp;

	lem.file = ft_lstrev(lem.file);
	tmp = lem.file;
	ft_printf("PRINTING FILE : \n\n");
	while (tmp)
	{
		ft_printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	lem.file = ft_lstrev(lem.file);
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

	ft_printf("PRINTING PATH :\n\n");
	tmp = lem.paths;
	while (tmp)
	{
		lst_rev(&tmp->lst);
		tmp_lst = tmp->lst;
		while (tmp_lst)
		{
			ft_printf("%s", tmp_lst->r->name);
			if (tmp_lst->next)
				ft_printf(" - ");
			tmp_lst = tmp_lst->next;
		}
		ft_printf("\n");
		lst_rev(&tmp->lst);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	print_coords_inf(t_env lem)
{
	t_path	*tmp;
	t_rlist	*tmp_lst;
	t_limit x;
	t_limit y;

	init_limits(&x, &y);
	tmp = lem.paths;
	while (tmp)
	{
		tmp_lst = tmp->lst;
		while (tmp_lst)
		{
			get_limits(tmp_lst->r, &x, &y);
			tmp_lst = tmp_lst->next;
		}
		tmp = tmp->next;
	}
	ft_dprintf(lem.args.v_fd, "%d %d %d %d\n", x.min, x.max, y.min, y.max);
}

void	print_visual_infos(t_env lem)
{
	t_path	*tmp;
	t_rlist *tmp_lst;

	ft_dprintf(lem.args.v_fd, "%d\n", lem.ants_nb);
	print_coords_inf(lem);
	ft_dprintf(lem.args.v_fd, "%s %s\n", lem.start->r->name, lem.end->r->name);
	tmp = lem.paths;
	while (tmp)
	{
		lst_rev(&tmp->lst);
		tmp_lst = tmp->lst;
		while (tmp_lst->next)
		{
			ft_dprintf(lem.args.v_fd, "%s %d %d %s %d %d\n",
					tmp_lst->r->name, tmp_lst->r->x, tmp_lst->r->y,
					tmp_lst->next->r->name, tmp_lst->next->r->x,
					tmp_lst->next->r->y);
			tmp_lst = tmp_lst->next;
		}
		lst_rev(&tmp->lst);
		tmp = tmp->next;
	}
}

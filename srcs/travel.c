/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:44:10 by agouby            #+#    #+#             */
/*   Updated: 2017/09/21 18:03:34 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	check_for_case(t_env *lem, t_rlist *lst_tmp, char *pri, size_t *id_box)
{
	char	ret;

	ret = 0;
	if (lst_tmp->r->has_ant == 0 &&
			ft_strequ(lst_tmp->next->r->name, lem->start->r->name))
		ret = next_is_start(lem, lst_tmp, pri, id_box);
	else if (ft_strequ(lst_tmp->r->name, lem->end->r->name) &&
			lst_tmp->next->r->has_ant == 1)
		cur_is_end(lst_tmp, pri);
	else if (lst_tmp->r->has_ant == 0 && lst_tmp->next->r->has_ant == 1)
		next_is_basic(lst_tmp, pri);
	return (ret);
}

void	go_throught_paths(t_env *lem)
{
	static size_t	id_box;
	char			pri;
	t_path			*paths_tmp;
	t_rlist			*lst_tmp;

	paths_tmp = lem->paths;
	while (paths_tmp)
	{
		lst_tmp = paths_tmp->lst;
		while (lst_tmp->next)
		{
			pri = 0;
			check_for_case(lem, lst_tmp, &pri, &id_box);
			if (pri)
			{
				if (lem->args.v)
					ft_dprintf(lem->args.v_fd, "L%d-%s ",
							lst_tmp->r->ant_id, lst_tmp->r->name);
				ft_printf("L%d-%s ", lst_tmp->r->ant_id, lst_tmp->r->name);
			}
			lst_tmp = lst_tmp->next;
		}
		paths_tmp = paths_tmp->next;
	}
}

void	travel_multipath(t_env *lem)
{
	lem->start->r->has_ant = lem->ants_nb;
	while (lem->end->r->has_ant != lem->ants_nb)
	{
		go_throught_paths(lem);
		if (lem->args.v)
			ft_dprintf(lem->args.v_fd, "\n");
		ft_printf("\n");
	}
}

void	travel_direct(t_env *lem)
{
	size_t	i;

	i = 1;
	while (i <= lem->ants_nb)
	{
		ft_printf("L%d-%s", i, lem->end->r->name);
		if (lem->args.v)
			ft_dprintf(lem->args.v_fd, "L%d-%s", i, lem->end->r->name);
		if (i != lem->ants_nb)
			ft_printf(" ");
		i++;
	}
	ft_printf("\n");
}

void	travel_ants(t_env *lem)
{
	ft_printf("SOLUTION :\n\n");
	if (lem->args.v)
		ft_dprintf(lem->args.v_fd, "SOLUTION\n");
	if (lem->direct)
		travel_direct(lem);
	else
		travel_multipath(lem);
	del_hash(lem->hash);
	del_paths(lem->paths);
	ft_lstdel(&lem->file, del_file);
}

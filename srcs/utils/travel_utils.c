/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   travel_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 23:09:56 by agouby            #+#    #+#             */
/*   Updated: 2017/09/19 23:12:24 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	next_is_start(t_env *lem, t_rlist *lst_tmp, char *pri, size_t *id_box)
{
	if (lem->start->r->has_ant <= 0)
		return (1);
	lst_tmp->r->has_ant++;
	lst_tmp->r->ant_id = ++(*id_box);
	lem->start->r->has_ant--;
	*pri = 1;
	return (0);
}

void	cur_is_end(t_rlist *lst_tmp, char *pri)
{
	lst_tmp->r->ant_id = lst_tmp->next->r->ant_id;
	lst_tmp->r->has_ant++;
	lst_tmp->next->r->has_ant--;
	*pri = 1;
}

void	next_is_basic(t_rlist *lst_tmp, char *pri)
{
	lst_tmp->r->ant_id = lst_tmp->next->r->ant_id;
	lst_tmp->r->has_ant++;
	lst_tmp->next->r->has_ant--;
	*pri = 1;
}

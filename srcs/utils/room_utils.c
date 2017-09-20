/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 17:24:02 by agouby            #+#    #+#             */
/*   Updated: 2017/09/20 10:24:12 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	got_double_room(t_env *lem, const char *line, size_t hash)
{
	t_rlist	*tmp;

	tmp = lem->hash[hash];
	if (!tmp)
		return (0);
	while (tmp)
	{
		if (ft_strequ(line, tmp->r->name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		deal_with_double(t_env *lem, t_parser *pars, char *line)
{
	if (pars->got_end || pars->got_start)
	{
		crit_err(lem, CERR_DUPR);
		read_and_delete(line, 1);
		del_hash(lem->hash);
		ft_strdel(&line);
		exit(1);
	}
	else
		warning(pars, line, WAR_ALEXIST);
}

void		get_room_infos(t_room **r, const char *line, char *slh)
{
	*r = (t_room *)malloc(sizeof(t_room));
	if (!((*r)->name = ft_strdup(line)))
		ft_memerr();
	get_r_coords(*r, slh);
	(*r)->nei = NULL;
	(*r)->al_vis = 0;
	(*r)->score = -1;
	(*r)->banned = 0;
	(*r)->ant_id = 0;
	(*r)->has_ant = 0;
}

void		create_room(t_env *lem, t_parser *pars, char *line)
{
	t_room	*r;
	char	*cpy;
	size_t	hash;

	cpy = pars->slh;
	*pars->slh = '\0';
	pars->slh++;
	hash = get_hash_index(line);
	if (got_double_room(lem, line, hash))
	{
		deal_with_double(lem, pars, line);
		*cpy = ' ';
	}
	else
	{
		get_room_infos(&r, line, pars->slh);
		rlist_add(&lem->hash[hash], rlist_new(r));
		if (pars->got_start)
			lem->start = lem->hash[hash];
		else if (pars->got_end)
			lem->end = lem->hash[hash];
		*cpy = ' ';
	}
}

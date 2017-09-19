/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 17:24:02 by agouby            #+#    #+#             */
/*   Updated: 2017/09/11 17:32:28 by agouby           ###   ########.fr       */
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

char		valid_room_name(const char *line, int *err)
{
	if (*line == ' ' || *line == 'L')
	{
		*err = ERR_RNAME;
		return (0);
	}
	return (1);
}

char		valid_room_coords(const char *line, int *err)
{
	while (*line)
	{
		if (!ft_isspace(*line) && !ft_isdigit(*line))
		{
			*err = ERR_COORD;
			return (0);
		}
		line++;
	}
	return (1);
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
		*cpy = ' ';
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

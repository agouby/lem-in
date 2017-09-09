/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 17:24:02 by agouby            #+#    #+#             */
/*   Updated: 2017/09/09 16:26:36 by agouby           ###   ########.fr       */
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
		if (ft_strequ(line, tmp->r.name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

char		valid_room_name(const char *line)
{
	if (*line == ' ' || *line == 'L')
		return (0);
	return (1);
}

char		valid_room_coords(const char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line) && !ft_isdigit(*line))
			return (0);
		line++;
	}
	return (1);
}

void		cpy_start_end(t_env *lem, t_parser *pars, size_t hash)
{
	if (pars->got_start)
		lem->start = lem->hash[hash];
	else if (pars->got_end)
		lem->end = lem->hash[hash];
}

void		create_room(t_env *lem, t_parser *pars, char *line)
{
	t_room	*r;
	char	*cpy;
	size_t	hash;

	r = (t_room *)malloc()
	cpy = pars->slh;
	*pars->slh = '\0';
	pars->slh++;
	hash = get_hash_index(line);
	if (got_double_room(lem, line, hash))
		*cpy = ' ';
	else
	{
		if (!(r.name = ft_strdup(line)))
			ft_memerr();
		get_r_coords(&r, pars->slh);
		r.nei = NULL;
		r.al_vis = 0;
		rlist_add(&lem->hash[hash], rlist_new(r));
		cpy_start_end(lem, pars, hash);
		*cpy = ' ';
	}
}

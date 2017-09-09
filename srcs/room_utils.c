/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 17:24:02 by agouby            #+#    #+#             */
/*   Updated: 2017/09/07 21:17:50 by agouby           ###   ########.fr       */
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

char	valid_room_name(const char *line)
{
	if (*line == ' ' || *line == 'L')
		return (0);
	return (1);
}

char	valid_room_coords(const char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line) && !ft_isdigit(*line))
			return (0);
		line++;
	}
	return (1);
}

void	create_room(t_env *lem, t_parser *pars, char *line, size_t cut)
{
	t_room	r;
	size_t	hash;

	*pars->slh = '\0';
	hash = get_hash_index(line);
	if (got_double_room(lem, line, hash))
	{
		*pars->slh = ' ';
		return ;
	}
	*pars->slh = ' ';
	r.name = ft_strndup(line, cut);
	while (line[cut] && ft_isspace(line[cut]))
		cut++;
	r.x = ft_atoi(line + cut);
	while (ft_isdigit(line[cut]))
		cut++;
	r.y = ft_atoi(line + cut);
	r.nei = NULL;
	rlist_add(&lem->hash[hash], rlist_new(r));
	if (pars->got_start)
		lem->start = lem->hash[hash];
	else if (pars->got_end)
		lem->end = lem->hash[hash];
}

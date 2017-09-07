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

void	rlist_add(t_rlist **old, t_rlist *new)
{
	new->next = *old;
	*old = new;
}

t_rlist	*rlist_new(t_room r)
{
	t_rlist *new;

	new = (t_rlist *)malloc(sizeof(t_rlist));
	new->r = r;
	new->next = NULL;
	return (new);
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
	size_t	i;
	size_t	hash;

	i = cut;
	if (!(r.name = ft_strndup(line, cut)))
		ft_memerr();
	while (line[i] && ft_isspace(line[i]))
		i++;
	r.x = ft_atoi(line + i);
	i = i + ft_count_digit(r.x, 10);
	r.y = ft_atoi(line + i);
	r.nei = NULL;
	hash = get_hash_index(r.name);
	rlist_add(&lem->hash[hash], rlist_new(r));
	if (pars->got_start)
		lem->start = lem->hash[hash];
	else if (pars->got_end)
		lem->end = lem->hash[hash];
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 13:33:58 by agouby            #+#    #+#             */
/*   Updated: 2017/09/09 17:02:47 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	push_t_in_r(t_env *lem, char *cur, char *nei, size_t h, size_t h_sec)
{
	t_rlist	*tmp;
	t_rlist	*tmp_nei;
	t_rlist	*tmp_sec;

	tmp = lem->hash[h];
	tmp_sec = lem->hash[h_sec];
	while (tmp && !ft_strequ(tmp->r->name, cur))
		tmp = tmp->next;
	tmp_nei = tmp->r->nei;
	while (tmp_nei)
	{
		if (ft_strequ(tmp_nei->r->name, nei))
			return ;
		tmp_nei = tmp_nei->next;
	}
	while (!ft_strequ(tmp_sec->r->name, nei))
		tmp_sec = tmp_sec->next;
	rlist_add(&tmp->r->nei, rlist_new(tmp_sec->r));
}

char	r_exists(t_rlist *tmp, const char *line)
{
	while (tmp)
	{
		if (ft_strequ(tmp->r->name, line))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	convert_tube(t_env *lem, t_parser *pars, char *line)
{
	char	*cpy;
	size_t	h;
	size_t	h_sec;
	char	w;

	w = 0;
	cpy = pars->slh;
	*pars->slh = '\0';
	pars->slh++;
	h = get_hash_index(line);
	h_sec = get_hash_index(pars->slh);
	if (!r_exists(lem->hash[h], line) && (w = 1) && lem->args.w)
		warning(pars, line, WAR_RUNKN);
	if (!r_exists(lem->hash[h_sec], pars->slh) && (w = 1) && lem->args.w)
		warning(pars, pars->slh, WAR_RUNKN);
	if (!w)
	{
		push_t_in_r(lem, line, pars->slh, h, h_sec);
		push_t_in_r(lem, pars->slh, line, h_sec, h);
	}
	*cpy = '-';
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:00:37 by agouby            #+#    #+#             */
/*   Updated: 2017/09/20 10:18:30 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	is_comment(const char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

char	is_command(const char *line)
{
	if (line[0] == '#' && line[1] == '#')
		return (1);
	return (0);
}

char	is_room(t_parser *pars, const char *line)
{
	if ((pars->slh = ft_strchr(line, ' ')))
		return (1);
	return (0);
}

char	is_tube(t_parser *pars, const char *line)
{
	if ((pars->slh = ft_strchr(line, '-')))
		return (1);
	return (0);
}

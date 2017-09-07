/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:40:07 by agouby            #+#    #+#             */
/*   Updated: 2017/09/07 21:03:44 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parsing_process(t_env *lem, t_parser *pars, char *line)
{
	if (is_comment(line))
		;
	else if (is_command(line))
		get_command(pars, line);
	else if (is_room(pars, line))
		get_room(lem, pars, line);
	else if (is_tube(pars, line))
		get_tube(lem, pars, line);
	else
		parse_error(pars, &line);
	ft_lstadd(&lem->file, push_in_list(line));
}

void	parse_map(t_env *lem)
{
	t_parser	pars;
	char		*line;

	ft_memset(&pars, 0, sizeof(t_parser));
	line = NULL;
	get_ants(lem, &pars);
	lem->hash = ft_memalloc(H_SIZE * sizeof(t_list *));
	while (!pars.err && (pars.gnl_ret = get_next_line(0, &line)))
	{
		parsing_process(lem, &pars, line);
	}
	read_and_delete(pars, line);
}

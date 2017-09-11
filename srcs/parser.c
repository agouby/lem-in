/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:40:07 by agouby            #+#    #+#             */
/*   Updated: 2017/09/11 01:30:05 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parsing_process(t_env *lem, t_parser *pars, char *line)
{
	if (is_comment(line))
		;
	else if (is_command(line))
		get_command(pars, line);
	else if (!pars->got_tube && is_room(pars, line))
		get_room(lem, pars, line);
	else if (is_tube(pars, line))
		get_tube(lem, pars, line);
	else
		parse_error(pars, &line);
	ft_lstadd(&lem->file, ft_lstnew_noalloc(line));
}

void	parse_map(t_env *lem)
{
	t_parser	pars;
	char		*line;
	ssize_t		gnl_ret;

	ft_memset(&pars, 0, sizeof(t_parser));
	line = NULL;
	gnl_ret = 0;
	get_ants(lem, gnl_ret);
	lem->hash = ft_memalloc(H_SIZE * sizeof(t_list *));
	while (!pars.err && (gnl_ret = get_next_line(0, &line)))
	{
		parsing_process(lem, &pars, line);
	}
	read_and_delete(line, gnl_ret);
}

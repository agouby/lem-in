/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:46:05 by agouby            #+#    #+#             */
/*   Updated: 2017/09/20 10:15:19 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parsing_process(t_env *lem, t_parser *pars, char *line)
{
	pars->ln++;
	if (is_comment(line))
		;
	else if (is_command(line))
		get_command(lem, pars, line);
	else if (!pars->got_tube && is_room(pars, line))
		get_room(lem, pars, line);
	else if (is_tube(pars, line))
	{
		get_tube(lem, pars, line);
	}
	else
		parse_err(lem, pars, &line, ERR_LINE);
	push_in_file(lem, line);
}

void	parse_map(t_env *lem)
{
	t_parser	pars;
	char		*line;
	ssize_t		gnl_ret;

	ft_memset(&pars, 0, sizeof(t_parser));
	init_err_tab(lem);
	line = NULL;
	gnl_ret = 0;
	get_ants(lem, &pars, &gnl_ret);
	lem->hash = ft_memalloc((H_SIZE) * sizeof(t_list *));
	while (!pars.err && (gnl_ret = get_next_line(0, &line)))
		parsing_process(lem, &pars, line);
	read_and_delete(line, gnl_ret);
	if (!pars.got_tube)
		quit_parsing(lem);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:25:35 by agouby            #+#    #+#             */
/*   Updated: 2017/09/09 16:55:52 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_ants(t_env *lem, t_parser *pars, ssize_t *gnl_ret)
{
	char	*line;

	line = NULL;
	*gnl_ret = get_next_line(0, &line);
	pars->ln++;	
	if (ft_strisdigit(line) && (lem->ants_nb = ft_atou(line)) > 0)
		push_in_file(lem, line);
	else
		parse_err(pars, &line, ERR_ANT);
}

void	get_command(t_parser *pars, char *line)
{
	if (ft_strequ(line, "##start"))
		pars->got_start++;
	else if (ft_strequ(line, "##end"))
		pars->got_end++;
//	else
//		command_unknown(line);
	if (pars->got_start > 1 || pars->got_end > 1)
		parse_err(pars, &line, ERR_CMD);
	else if (pars->got_start && pars->got_end)
		parse_err(pars, &line, ERR_CMD);
}

void	get_room(t_env *lem, t_parser *pars, char *line)
{
	if (!valid_room_name(line))
	{
		parse_err(pars, &line, ERR_RNAME);
		return ;
	}
	if (!valid_room_coords(pars->slh))
	{
		parse_err(pars, &line, ERR_COORD);
		return ;
	}
	if (!pars->got_room)
		pars->got_room = 1;
	if (pars->got_start || pars->got_end)
		pars->command_cnt++;
	create_room(lem, pars, line);
	pars->got_end = 0;
	pars->got_start = 0;
}

void	get_tube(t_env *lem, t_parser *pars, char *line)
{
	if (!pars->got_tube)
		pars->got_tube = 1;
	if (pars->command_cnt != 2 || *line == '-')
	{
		parse_err(pars, &line, ERR_CMD);
		return ;
	}
	convert_tube(lem, pars, line);
}

void	get_r_coords(t_room *r, char *line)
{
	while (*line && ft_isspace(*line))
		line++;
	r->x = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	r->y = ft_atoi(line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 16:25:35 by agouby            #+#    #+#             */
/*   Updated: 2017/09/19 22:43:59 by agouby           ###   ########.fr       */
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
		parse_err(lem, pars, &line, ERR_ANTS);
}

void	get_command(t_env *lem, t_parser *pars, char *line)
{
	if (ft_strequ(line, "##start"))
		pars->got_start++;
	else if (ft_strequ(line, "##end"))
		pars->got_end++;
	else if (lem->args.w)
		warning(pars, line, WAR_CMDUNKN);
	if (pars->got_start > 1 || pars->got_end > 1)
		parse_err(lem, pars, &line, ERR_CMD);
	else if (pars->got_start && pars->got_end)
		parse_err(lem, pars, &line, ERR_CMD);
}

void	get_room(t_env *lem, t_parser *pars, char *line)
{
	int	err;

	err = 0;
	if (!valid_room_name(line, &err) || !valid_room_coords(pars->slh, &err))
	{
		parse_err(lem, pars, &line, err);
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
	int	err;

	err = 0;
	if (!pars->got_tube)
		pars->got_tube = 1;
	if (pars->command_cnt != 2)
		err = ERR_CMD;
	else if (*line == '-')
		err = ERR_TNAME;
	if (err)
	{
		parse_err(lem, pars, &line, err);
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

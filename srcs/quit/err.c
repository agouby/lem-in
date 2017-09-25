/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:42:14 by agouby            #+#    #+#             */
/*   Updated: 2017/09/26 00:52:41 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_err_tab(t_env *lem)
{
	lem->err_t[ERR_ANTS] = "No ants or too many ants.";
	lem->err_t[ERR_RNAME] = "Room has invalid name.";
	lem->err_t[ERR_COORD] = "Room has invalid coordinates.";
	lem->err_t[ERR_LINE] = "Line has invalid format.";
	lem->err_t[ERR_CMD] = "Unique or multiple start or end commands.";
	lem->err_t[ERR_TNAME] = "Tube has invalid name.";
	lem->err_t[CERR_NOTUBE] = "Tubes are missing.";
	lem->err_t[CERR_NOPATH] = "No path found.";
	lem->err_t[CERR_DUPR] = "Duplicated start or end.";
}

void	parse_err(t_env *lem, t_parser *pars, char **line, int err)
{
	ft_printf("** PARSING ERROR **\n");
	ft_printf("On line %d : %s\n\n", pars->ln, lem->err_t[err]);
	ft_strdel(line);
	pars->err = 1;
}

void	warning(t_parser *pars, char *line, int w)
{
	ft_printf("** WARNING **\n");
	if (w == WAR_RUNKN)
		ft_printf("On line %d : %s doesn't exist.\n\n", pars->ln, line);
	else if (w == WAR_CMDUNKN)
		ft_printf("On line %d : %s is unknown.\n\n", pars->ln, line);
	else if (w == WAR_ALEXIST)
		ft_printf("On line %d : %s already exist\n\n", pars->ln, line);
	else if (w == WAR_RLONELY)
		ft_printf("Room <%s> is not connected to anything.\n\n", line);
}

void	crit_err(t_env *lem, int err)
{
	ft_printf("** CRITICAL ERROR **\n");
	ft_printf("%s\nQuitting.\n", lem->err_t[err]);
}

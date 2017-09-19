/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:42:14 by agouby            #+#    #+#             */
/*   Updated: 2017/09/19 22:42:15 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_err_tab(t_env *lem)
{
	lem->err_t[ERR_ANTS] = "No ants.";
	lem->err_t[ERR_RNAME] = "Room has invalid name.";
	lem->err_t[ERR_COORD] = "Room has invalid coordinates.";
	lem->err_t[ERR_LINE] = "Line has invalid format.";
	lem->err_t[ERR_CMD] = "Multiple start or end commands.";
	lem->err_t[ERR_TNAME] = "Tube has invalid name.";
	lem->err_t[ERR_NOPATH] = "No path found.";
	lem->err_t[CERR_NOTUBE] = "Tubes are missing.";
	lem->err_t[CERR_NOPATH] = "No path found.";
}

void	parse_err(t_env *lem, t_parser *pars, char **line, int err)
{
	ft_printf("** PARSING ERROR **\n");
	ft_printf("On line %d : %s\n\n", pars->ln, lem->err_t[err]);
	if (lem->args.pfile)
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
}

void	crit_err(t_env *lem, int err)
{
	ft_printf("** CRITICAL ERROR **\n");
	ft_printf("%s\nQuitting.\n", lem->err_t[err]);
}

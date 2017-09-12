#include "lem_in.h"

void	init_err_tab(t_env *lem)
{
	lem->err[ERR_ANTS] = "No ants.";
	lem->err[ERR_RNAME] = "Room has invalid name.";
	lem->err[ERR_COORD] = "Room has invalid coordinates.";
	lem->err[ERR_LINE]	= "Line has invalid format.";
	lem->err[ERR_CMD] =	"Multiple start or end commands.";
	lem->err[ERR_TNAME] = "Tube has invalid name.";
	lem->err[ERR_NOPATH] = "No path found.";
	lem->err[WAR_RUNKN] = "Room doesn't exist.";
	lem->err[WAR_RLONE] = "Room has no neighbours.";
	lem->err[WAR_CMDUNKN] = "Command is unknown.";
}

void	parse_err(t_env *lem, t_parser *pars, char **line, char err)
{
	(void)err;
	ft_printf("** PARSING ERROR **\n");
	ft_printf("On line %d : %s\n", pars->ln, lem->err[5]);
	ft_strdel(line);
	pars->err = 1;
	return ;
}

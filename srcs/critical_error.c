#include "lem_in.h"

void	ants_err(char **line, ssize_t gnl_ret)
{
	ft_strdel(line);
	read_and_delete(*line, gnl_ret);
	ft_print_error("No ants.\n");
}

#include "lem_in.h"

void	usage_err()
{
	ft_print_error("Error usage");	
}

void	get_args(t_env *lem, const char **av)
{
	av++;
	while (*av)
	{
		if (ft_strequ("-w", *av))
			lem->args.w = 1;
		else if (ft_strequ("-pinf", *av))
			lem->args.pinf = 1;
		else if (ft_strequ("-ppath", *av))
			lem->args.ppath = 1;
		else if (ft_strequ("-pfile", *av))
			lem->args.pfile = 1;
		else if (ft_strnequ("-maxpath=", *av, 9))
			lem->args.max_path = ft_atou(*av + 9);
		else
			usage_err();
	av++;
	}
/*	ft_printf("PINF = %d\n", lem->args.pinf);
	ft_printf("PPATH = %d\n", lem->args.ppath);
	ft_printf("PFILE = %d\n", lem->args.pfile);
	ft_printf("MAX_PATH = %d\n", lem->args.max_path);
*/
}


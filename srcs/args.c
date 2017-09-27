/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:25:55 by agouby            #+#    #+#             */
/*   Updated: 2017/09/26 16:30:53 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	err_usage(void)
{
	ft_printf("Usage : ./lem-in [OPTIONS] < [MAP]\n\n");
	ft_printf("List of options that are available :\n\n");
	ft_printf("-v : Start visualizer with \"; ./visual.fx\".\n");
	ft_printf("-w : Check for warnings\n-nopfile : Don't print the file.\n");
	ft_printf("-pinf  : Print infos about the rooms and their connexions.\n");
	ft_printf("-ppath : Print found paths.\n");
	ft_printf("-maxpath=[N] : Specify N to get the maximum paths available.\n");
	exit(1);
}

void	check_lonely_rooms(t_env lem)
{
	t_rlist		*tmp;
	t_parser	*pars;
	size_t		i;

	i = 0;
	pars = NULL;
	if (!lem.args.w)
		return ;
	while (i < H_SIZE)
	{
		if (lem.hash[i])
		{
			tmp = lem.hash[i];
			while (tmp)
			{
				if (!tmp->r->nei)
					warning(pars, tmp->r->name, WAR_RLONELY);
				tmp = tmp->next;
			}
		}
		i++;
	}
}

void	get_args(t_env *lem, const char **av)
{
	lem->args.v_fd = open("visual_infos", O_RDWR | O_CREAT, 0666);
	av++;
	while (*av)
	{
		if (ft_strequ("-w", *av))
			lem->args.w = 1;
		else if (ft_strequ("-pinf", *av))
			lem->args.pinf = 1;
		else if (ft_strequ("-ppath", *av))
			lem->args.ppath = 1;
		else if (ft_strequ("-nopfile", *av))
			lem->args.nopfile = 1;
		else if (ft_strnequ("-maxpath=", *av, 9))
			lem->args.max_path = ft_atou(*av + 9);
		else if (ft_strequ("-v", *av))
			lem->args.v = 1;
		else
			err_usage();
		av++;
	}
}

void	print_args(t_env lem)
{
	if (!lem.args.nopfile)
		print_file(lem);
	if (lem.args.pinf)
		print_hash(lem);
	if (lem.args.ppath)
		print_paths(lem);
	if (lem.args.v)
		print_visual_infos(lem);
}

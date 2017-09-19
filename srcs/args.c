/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:25:55 by agouby            #+#    #+#             */
/*   Updated: 2017/09/20 00:05:35 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
			ft_print_error("Error usage");
		av++;
	}
}

void	print_args(t_env lem)
{
	if (lem.args.pfile)
		print_file(lem);
	if (lem.args.pinf)
		print_hash(lem);
	if (lem.args.ppath)
		print_paths(lem);
}

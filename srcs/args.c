/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:25:55 by agouby            #+#    #+#             */
/*   Updated: 2017/09/19 22:26:40 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

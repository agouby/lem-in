/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:20:42 by agouby            #+#    #+#             */
/*   Updated: 2017/09/09 15:06:57 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_args(t_env lem, const char **av)
{
	while (*av)
	{
		if (ft_strequ(*av, "-ph"))
			print_hash(&lem);
		else if (ft_strequ(*av, "-pf"))
			print_file(lem);
		av++;
	}
}

int		main(int ac, const char **av)
{
	t_env	lem;

	(void)ac;
	ft_memset(&lem, 0, sizeof(lem));
	parse_map(&lem);
	check_args(lem, av);
	get_paths(&lem);
	return (0);
}

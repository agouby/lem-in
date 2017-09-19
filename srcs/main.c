/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:20:42 by agouby            #+#    #+#             */
/*   Updated: 2017/09/19 23:55:11 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, const char **av)
{
	t_env	lem;

	(void)ac;
	ft_memset(&lem, 0, sizeof(lem));
	get_args(&lem, av);
	parse_map(&lem);
	check_lonely_rooms(lem);
	get_paths(&lem);
	print_args(lem);
	travel_ants(&lem);
	return (0);
}

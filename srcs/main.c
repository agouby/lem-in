/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:20:42 by agouby            #+#    #+#             */
/*   Updated: 2017/09/21 17:55:41 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, const char **av)
{
	t_env	lem;

	(void)ac;
	ft_memset(&lem, 0, sizeof(lem));
	system("rm -f visual_infos");
	get_args(&lem, av);
	if (!lem.args.v)
		ft_dprintf(lem.args.v_fd, "ERROR");
	parse_map(&lem);
	check_lonely_rooms(lem);
	get_paths(&lem);
	print_args(lem);
	travel_ants(&lem);
	if (lem.args.v)
		close(lem.args.v_fd);
	return (0);
}

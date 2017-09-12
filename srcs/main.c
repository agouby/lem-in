/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:20:42 by agouby            #+#    #+#             */
/*   Updated: 2017/09/11 21:56:58 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int ac, const char **av)
{
	t_env	lem;

	(void)ac;
	ft_memset(&lem, 0, sizeof(lem));
	init_err_tab(&lem);
	get_args(&lem, av);
	parse_map(&lem);
//	get_paths(&lem);
	return (0);
}

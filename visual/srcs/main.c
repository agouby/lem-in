/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:14:54 by agouby            #+#    #+#             */
/*   Updated: 2017/09/23 01:52:27 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		main(void)
{
	t_env	v;

	ft_memset(&v, 0, sizeof(t_env));
	v.cur_shot = -1;
	v.fd = open("visual_infos", O_RDONLY);
	if (v.fd == -1)
		ft_print_error("File not found.\n");
	read_file(&v);
	get_infos(&v);
	mlx_hook(v.mlx.win, 2, 3, key_hook, &v);
	mlx_loop(v.mlx.ptr);
	return (0);
}

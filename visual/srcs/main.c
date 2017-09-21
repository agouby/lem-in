/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:14:54 by agouby            #+#    #+#             */
/*   Updated: 2017/09/21 22:14:10 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	print_shit(t_env v)
{
	t_coord	i;
	t_coord	off;

	i.y = 0;
	off.y = OFFSET;
	while (i.y < MAP_Y)
	{
		i.x = 0;
		while (i.x < MAP_X)
		{
			off.x = i.x + OFFSET;
			draw_point(&v, off, 0xFFFFFF);
			i.x++;
		}
		off.y = i.y + OFFSET;
		i.y++;
	}
}

int		main(void)
{
	t_env	v;

	ft_memset(&v, 0, sizeof(t_env));
	v.fd = open("visual_infos", O_RDONLY);
	if (v.fd == -1)
		ft_print_error("File not found.\n");
	read_file(&v);
	v.mlx.ptr = mlx_init();
	create_win(&v);
	create_img(&v);
	if (v.err)
		print_err(&v);
	else
	{
		get_infos(&v);
//		print_shit(v);
		mlx_put_image_to_window(v.mlx.ptr, v.mlx.win, v.mlx.img, 0, 0);
	}
	mlx_hook(v.mlx.win, 2, 3, key_hook, &v);
	mlx_loop(v.mlx.ptr);
	return (0);
}

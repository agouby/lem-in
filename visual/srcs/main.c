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

void	print_lol(t_env *v)
{
	t_rlist	*tmp;

	tmp = v->list;
	while (tmp)
	{
		mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.room, tmp->r->c.x + 45 - 25, tmp->r->c.y + 45 - 25);
		tmp = tmp->next;
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
	clear_img(&v);
	int size = 50;
	int sx = 2000;
	int sy = 1000;
	v.mlx.room = mlx_xpm_file_to_image(v.mlx.ptr, "visual/img/room.xpm", &size, &size);
	v.mlx.back = mlx_xpm_file_to_image(v.mlx.ptr, "visual/img/back.xpm", &sx, &sy);
	if (v.err)
		print_err(&v);
	else
		get_infos(&v);
	mlx_put_image_to_window(v.mlx.ptr, v.mlx.win, v.mlx.back, 0, 0);
	mlx_put_image_to_window(v.mlx.ptr, v.mlx.win, v.mlx.img, 45, 45);
	print_lol(&v);
	mlx_hook(v.mlx.win, 2, 3, key_hook, &v);
	mlx_loop(v.mlx.ptr);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:01:48 by agouby            #+#    #+#             */
/*   Updated: 2017/09/25 21:30:00 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	clear_map(t_env *v)
{
	t_coord	i;

	i.y = 0;
	while (i.y < MAP_Y + OFFSET * 2)
	{
		i.x = 0;
		while (i.x < MAP_X + OFFSET * 2)
		{
			draw_point(v, i, 0x181818);
			i.x++;
		}
		i.y++;
	}
}

void	print_rooms(t_env *v)
{
	t_rlist	*tmp;
	void	*room;

	tmp = v->list;
	while (tmp)
	{
		if (ft_strequ(tmp->r->name, v->start.name))
			room = v->mlx.room_s;
		else if (ft_strequ(tmp->r->name, v->end.name))
			room = v->mlx.room_s;
		else
			room = v->mlx.room_f;
		mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, room,
				tmp->r->c.x + 45 - 25, tmp->r->c.y + 45 - 25);
		tmp = tmp->next;
	}
}

void	print_back(t_env *v)
{
	t_coord	back_s;

	back_s.x = 2000;
	back_s.y = 1000;
	v->mlx.back = mlx_xpm_file_to_image(v->mlx.ptr,
			"visual/img/back.xpm", (int *)&back_s.x, (int *)&back_s.y);
	if (!v->mlx.back)
		ft_print_error("back.xpm missing.\n");
	mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.back, 0, 0);
}

void	print_map(t_env *v)
{
	int	room_s;

	room_s = 50;
	if (!(v->mlx.room_f = mlx_xpm_file_to_image(v->mlx.ptr,
					"visual/img/room_f.xpm", &room_s, &room_s)))
		ft_print_error("room_f.xpm missing.\n");
	if (!(v->mlx.room_t = mlx_xpm_file_to_image(v->mlx.ptr,
					"visual/img/room_t.xpm", &room_s, &room_s)))
		ft_print_error("room_t.xpm missing.\n");
	if (!(v->mlx.room_s = mlx_xpm_file_to_image(v->mlx.ptr,
					"visual/img/room_s.xpm", &room_s, &room_s)))
		ft_print_error("room_s.xpm missing.\n");
	mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->mlx.map, 45, 45);
	print_rooms(v);
}

void	print_inf(t_env *v)
{
	print_nb(v, v->nb_paths, 1670, 81);
	print_nb(v, v->nb_shots, 1670, 137);
	print_nb(v, v->nb_ants, 1670, 196);
	print_nb(v, v->nb_rooms, 1670, 253);
}

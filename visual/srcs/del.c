/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 21:19:43 by agouby            #+#    #+#             */
/*   Updated: 2017/09/25 21:20:06 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	del_rooms(t_rlist **list)
{
	t_rlist *tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->r->name);
		free((*list)->r);
		free((*list));
		(*list) = tmp;
	}
}

void	del_mlx(t_env *v)
{
	ft_lstdel(&v->file, del_file);
	mlx_destroy_image(v->mlx.ptr, v->mlx.map);
	mlx_destroy_image(v->mlx.ptr, v->mlx.back);
	mlx_destroy_image(v->mlx.ptr, v->mlx.ze);
	mlx_destroy_image(v->mlx.ptr, v->mlx.tw);
	mlx_destroy_image(v->mlx.ptr, v->mlx.th);
	mlx_destroy_image(v->mlx.ptr, v->mlx.fo);
	mlx_destroy_image(v->mlx.ptr, v->mlx.fi);
	mlx_destroy_image(v->mlx.ptr, v->mlx.si);
	mlx_destroy_image(v->mlx.ptr, v->mlx.se);
	mlx_destroy_image(v->mlx.ptr, v->mlx.ei);
	mlx_destroy_image(v->mlx.ptr, v->mlx.ni);
	mlx_destroy_window(v->mlx.ptr, v->mlx.win);
	del_rooms(&v->list);
}

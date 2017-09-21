/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:19:06 by agouby            #+#    #+#             */
/*   Updated: 2017/09/21 16:26:55 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	print_list(t_rlist *list)
{
	t_rlist *tmp;

	tmp = list;
	while (tmp)
	{
		ft_printf("%s (%d, %d) - ", tmp->r->name, tmp->r->c.x, tmp->r->c.y);
		tmp = tmp->next;
	}
}

void	read_file(t_env *v)
{
	char	*line;

	line = NULL;
	ft_printf("PRINT OF VISUALIZER\n");
	v->mlx.ptr = mlx_init();
	if (v->err)
		return ;
	create_win(v);
	v->img = mlx_new_image(v->mlx.ptr, WIDTH, HEIGHT);	
//	v->pixel_img = mlx_get_data_addr(v->img, &(v->bpp), &(v->s_line), &(v->ed));
	while (get_next_line(v->fd, &line))
	{
		ft_printf("%s\n", line);
//		check_for_error(v, line);
//		if (ft_strequ(line, "SOLUTION") && (v->got_paths = 1))
//			ft_strdel(&line);
//		else if (!v->got_paths)
//			;
//		else
//			get_solution(v, line);
	}
//	mlx_put_image_to_window(v->mlx.ptr, v->mlx.win, v->img, 0, 0);
//	print_list(v->list);
//	ft_printf("S = %s, E = %s\n", v->s->name, v->e->name);

}

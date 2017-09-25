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
	mlx_destroy_window(v->mlx.ptr, v->mlx.win);
	del_rooms(&v->list);
}

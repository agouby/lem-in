#include "visual.h"

void	del_mlx(t_env *v)
{
	ft_lstdel(&v->file, del_file);
	mlx_destroy_image(v->mlx.ptr, v->mlx.map);
	mlx_destroy_image(v->mlx.ptr, v->mlx.back);
	mlx_destroy_window(v->mlx.ptr, v->mlx.win);
}

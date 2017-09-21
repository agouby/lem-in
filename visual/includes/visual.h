/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:15:44 by agouby            #+#    #+#             */
/*   Updated: 2017/09/21 22:53:50 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "ft_printf.h"
# include "mlx.h"
# include "key_macos.h" 
# include <fcntl.h>

# define WIN_X	2000
# define WIN_Y	1000
# define OFFSET 50
# define MAP_X	((WIN_X / 2) - 2 * OFFSET)
# define MAP_Y	(WIN_Y - 2 * OFFSET)

# define LN_CLR	0x8F8F8F

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	char	*pixel_img;
	void	*img;
	int		bpp;
	int		ed;
	int		s_line;
}				t_mlx;

typedef struct	s_room
{
	char	*name;
	t_coord	c;
}				t_room;

typedef struct	s_rlist
{
	t_room			*r;
	struct s_rlist	*next;
}				t_rlist;

typedef struct	s_bres
{
	int			dx;
	int			dy;
	double		sx;
	double		sy;
	double		err;
	double		e2;
}				t_bres;

typedef struct	s_limit
{
	size_t	min;
	size_t	max;
}				t_limit;

typedef struct	s_env
{
	int		fd;
	char	err;
	char	got_paths;
	t_rlist	*list;
	t_list	*file;
	t_limit	x;
	t_limit	y;
	float	fac_x;
	float	fac_y;
	t_coord	dist;
	t_mlx	mlx;
}				t_env;

void			read_file(t_env *v);
void			check_for_error(t_env *v);
void			create_win(t_env *v);
int				key_hook(int key);
void			print_map(t_env *v);
void			print_err(t_env *v);
t_rlist			*rlist_newalloc(t_room *r);
t_rlist			*rlist_new(t_room *r);
void			rlist_add(t_rlist **old, t_rlist *n);
void			rlist_addb(t_rlist **old, t_rlist *n);
void			draw_point(t_env *v, t_coord p, int color);
t_bres			draw_line_set(t_coord p1, t_coord p2);
void			draw_line(t_env *v, t_coord p1, t_coord p2);
char			*get_room(t_env *v, char *line, t_room **r);
void			get_infos(t_env *v);
void			print_list(t_rlist *list);
void			create_img(t_env *v);

#endif

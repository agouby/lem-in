/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:15:44 by agouby            #+#    #+#             */
/*   Updated: 2017/09/25 22:00:58 by agouby           ###   ########.fr       */
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

# define OFFSET 75

# define MAP_X (1303 - 2 * OFFSET)
# define MAP_Y	(912 - 2 * OFFSET)

# define LN_CLR	0x8F8F8F

typedef struct	s_mlx
{
	void	*ptr;
	void	*win;
	char	*pixel_img;
	void	*map;
	void	*room_f;
	void	*room_t;
	void	*room_s;
	void	*room_e;
	void	*ze;
	void	*on;
	void	*tw;
	void	*th;
	void	*fo;
	void	*fi;
	void	*si;
	void	*se;
	void	*ei;
	void	*ni;
	void	*back;
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
	char	**sol;
	size_t	nb_shots;
	size_t	nb_rooms;
	size_t	nb_ants;
	long	cur_shot;
	size_t	nb_paths;
	t_rlist	*list;
	t_list	*file;
	t_room	start;
	t_room	end;
	t_limit	x;
	t_limit	y;
	float	fac_x;
	float	fac_y;
	char	direct;
	t_coord	dist;
	t_mlx	mlx;
}				t_env;

void			read_file(t_env *v);
void			check_for_error(t_env *v);
void			create_win(t_env *v);
int				key_hook(int key, t_env *v);
void			print_err(t_env *v);
t_rlist			*rlist_new(t_room *r);
void			rlist_add(t_rlist **old, t_rlist *n);
void			rlist_addb(t_rlist **old, t_rlist *n);
void			draw_point(t_env *v, t_coord p, int color);
t_bres			draw_line_set(t_coord p1, t_coord p2);
void			draw_line(t_env *v, t_coord p1, t_coord p2);
char			*get_room(t_env *v, char *line, t_room **r);
void			get_infos(t_env *v);
void			print_list(t_rlist *list);
void			create_map(t_env *v);
void			clear_map(t_env *v);
void			start_mlx(t_env *v);
void			print_back(t_env *v);
void			print_map(t_env *v);
void			print_shot(t_env *v);
void			print_rooms(t_env *v);
void			del_file(void *content, size_t size);
void			del_mlx(t_env *v);
char			check_exist(t_rlist *list, char *line);
void			print_inf(t_env *v);
void			print_nb(t_env *v, int n, int x, int y);
void			print_char(t_env *v, char c, int x, int y);
void			get_connexions(t_env *v, char *line);
void			get_limits(t_env *v, char *line);
void			get_start_and_end(t_env *v, char *line);
void			get_sol_tab(t_env *v, t_list *list);

#endif

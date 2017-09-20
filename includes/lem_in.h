/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:14:55 by agouby            #+#    #+#             */
/*   Updated: 2017/09/20 10:24:49 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_printf.h"
# include "parser.h"

# define H_SIZE		100
# define MAX_PATH	1000000

typedef struct	s_room
{
	char			*name;
	int				al_vis;
	ssize_t			score;
	unsigned char	banned;
	struct s_rlist	*nei;
	size_t			ant_id;
	size_t			has_ant;
	size_t			x;
	size_t			y;
}				t_room;

typedef struct	s_rlist
{
	t_room			*r;
	struct s_rlist	*next;
}				t_rlist;

typedef struct	s_path
{
	t_rlist			*lst;
	struct s_path	*next;
}				t_path;

typedef struct	s_args
{
	unsigned char	pinf;
	unsigned char	pfile;
	unsigned char	ppath;
	unsigned char	w;
	size_t			max_path;
}				t_args;

typedef struct	s_env
{
	size_t			ants_nb;
	unsigned char	direct;
	t_rlist			**hash;
	t_rlist			*start;
	t_rlist			*end;
	t_path			*paths;
	t_rlist			*queue;
	t_list			*file;
	t_args			args;
	char			*err_t[NB_ERR + 1];
	size_t			start_fnd;
}				t_env;

void			parse_map(t_env *lem);
void			del_file(void *content, size_t size);
void			create_room(t_env *lem, t_parser *pars, char *line);
void			convert_tube(t_env *lem, t_parser *pars, char *line);
char			is_comment(const char *line);
char			is_command(const char *line);
char			is_room(t_parser *pars, const char *line);
char			is_tube(t_parser *pars, const char *line);
char			valid_room_name(const char *line, int *err);
char			valid_room_coords(const char *line, int *err);
void			get_ants(t_env *lem, t_parser *pars, ssize_t *gnl_ret);
void			get_command(t_env *lem, t_parser *pars, char *line);
void			get_room(t_env *lem, t_parser *pars, char *line);
void			get_tube(t_env *lem, t_parser *pars, char *line);
void			parse_err(t_env *lem, t_parser *pars, char **line, int err);
void			command_unknown(const char *line);
void			read_and_delete(char *line, ssize_t gnl_ret);
void			print_hash(t_env lem);
size_t			get_hash_index(const char *str);
void			ants_err(char **line, ssize_t gnl_ret);
t_rlist			*rlist_new(t_room *r);
t_rlist			*rlist_newalloc(t_room *r);
void			rlist_add(t_rlist **old, t_rlist *fresh);
void			print_file(t_env lem);
void			get_r_coords(t_room *r, char *line);
void			get_paths(t_env *lem);
t_rlist			*del_last_queue(t_rlist **cur);
void			get_args(t_env *lem, const char **av);
void			push_in_file(t_env *lem, char *line);
void			init_err_tab(t_env *lem);
void			warning(t_parser *pars, char *line, int w);
void			crit_err(t_env *lem, int err);
void			quit_parsing(t_env *lem);
void			del_hash(t_rlist **hash);
void			path_add(t_path **old, t_path *n);
t_path			*path_new(t_rlist *lst);
t_path			*path_rev(t_path *path);
void			quit_path(t_env *lem);
void			travel_ants(t_env *lem);
char			next_is_start(t_env *le, t_rlist *l, char *pri, size_t *id_box);
void			cur_is_end(t_rlist *lst_tmp, char *pri);
void			next_is_basic(t_rlist *lst_tmp, char *pri);
int				alrdy_in_queue(char *name, t_rlist *queue);
void			write_nei_in_queue(t_env *lem, t_room *r);
void			del_queue(t_rlist **queue);
void			init_al_vis(t_rlist **hash);
t_rlist			*get_next_room(t_env *lem, t_room *cur);
unsigned char	is_in_list(t_rlist *list, char *str);
size_t			get_start_nei(t_rlist *start);
void			print_args(t_env lem);
void			print_paths(t_env lem);
void			check_lonely_rooms(t_env lem);
void			del_paths(t_path *paths);
char			valid_room_name(const char *line, int *err);
char			valid_room_coords(const char *line, int *err);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:14:55 by agouby            #+#    #+#             */
/*   Updated: 2017/09/11 21:56:43 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_printf.h"
# include "parser.h"

# define H_SIZE 10000000

typedef struct	s_room
{
	char	*name;
	int 			al_vis;
	ssize_t			score;
	unsigned char	banned;
	struct s_rlist	*nei;
	size_t			x;
	size_t			y;
}				t_room;

typedef struct	s_rlist
{
	t_room			*r;
	struct s_rlist	*next;
}				t_rlist;

typedef struct	s_env
{
	size_t			ants_nb;
	unsigned char	direct;
	t_rlist			**hash;
	t_rlist			*start;
	t_rlist			*end;
	t_list			*paths;
	t_rlist			*queue;
	t_list			*file;
	size_t			start_fnd;
}				t_env;

void			parse_map(t_env *lem);
t_list			*push_in_list(char *line);
void			del_file(void *content, size_t size);
void			create_room(t_env *lem, t_parser *pars, char *line);
void			convert_tube(t_env *lem, t_parser *pars, char *line);
char			is_comment(const char *line);
char			is_command(const char *line);
char			is_room(t_parser *pars, const char *line);
char			is_tube(t_parser *pars, const char *line);
char			valid_room_name(const char *line);
char			valid_room_coords(const char *line);
void			get_ants(t_env *lem, ssize_t gnl_ret);
void			get_command(t_parser *pars, char *line);
void			get_room(t_env *lem, t_parser *pars, char *line);
void			get_tube(t_env *lem, t_parser *pars, char *line);
void			parse_error(t_parser *pars, char **line);
void			command_unknown(const char *line);
void			read_and_delete(char *line, ssize_t gnl_ret);
void			print_hash(t_env *lem);
size_t			get_hash_index(const char *str);
void			ants_err(char **line, ssize_t gnl_ret);
t_rlist			*rlist_new(t_room *r);
t_rlist			*rlist_newalloc(t_room *r);
void			rlist_add(t_rlist **old, t_rlist *fresh);
void			print_file(t_env lem);
void			get_r_coords(t_room *r, char *line);
void			get_paths(t_env *lem);
t_rlist			*del_last_queue(t_rlist **cur);

#endif

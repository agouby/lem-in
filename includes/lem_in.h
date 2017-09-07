/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:14:55 by agouby            #+#    #+#             */
/*   Updated: 2017/09/07 21:57:19 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_printf.h"
# include "parser.h"

# define H_SIZE 1

typedef struct	s_room
{
	char	*name;
	t_list	*nei;
	size_t	x;
	size_t	y;
}				t_room;

typedef struct	s_rlist
{
	t_room			r;
	struct s_rlist	*next;
}				t_rlist;

typedef struct	s_env
{
	size_t	ants_nb;
	t_rlist	**hash;
	t_rlist	*start;
	t_rlist	*end;
	t_list	*file;
}				t_env;

void			parse_map(t_env *lem);
t_list			*push_in_list(char *line);
void			del_file(void *content, size_t size);
void			create_room(t_env *lem, t_parser *pars, char *line, size_t cut);
void			convert_tube(t_env *lem, char *line, size_t cut);
char			is_comment(const char *line);
char			is_command(const char *line);
char			is_room(t_parser *pars, const char *line);
char			is_tube(t_parser *pars, const char *line);
char			valid_room_name(const char *line);
char			valid_room_coords(const char *line);
void			get_ants(t_env *lem, t_parser *pars);
void			get_command(t_parser *pars, char *line);
void			get_room(t_env *lem, t_parser *pars, char *line);
void			get_tube(t_env *lem, t_parser *pars, char *line);
void			parse_error(t_parser *pars, char **line);
void			command_unknown(const char *line);
void			read_and_delete(t_parser pars, char *line);
void			print_hash(t_env *lem);
size_t			get_hash_index(const char *str);

#endif

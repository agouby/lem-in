/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:19:06 by agouby            #+#    #+#             */
/*   Updated: 2017/09/23 00:29:07 by agouby           ###   ########.fr       */
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

void	print_file(t_list *file)
{
	t_list	*tmp;

	tmp = file;
	ft_printf("\nPRINTING FILE :\n\n");
	while (tmp)
	{
		ft_printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}

void	del_file(void *content, size_t size)
{
	(void)size;
	ft_strdel((char **)&content);
}

void	read_file(t_env *v)
{
	char	*line;

	line = NULL;
	while (get_next_line(v->fd, &line))
		ft_lstadd(&v->file, ft_lstnew_noalloc(line));
	ft_strdel(&line);
	v->file = ft_lstrev(v->file);
	check_for_error(v);
}

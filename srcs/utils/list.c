/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:59:31 by agouby            #+#    #+#             */
/*   Updated: 2017/09/07 16:45:28 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	del_file(void *content, size_t size)
{
	(void)size;
	ft_strdel((char **)&content);
}

void	push_in_file(t_env *lem, char *line)
{
	if (lem->args.pfile && line)
		ft_lstadd(&lem->file, ft_lstnew_noalloc(line));
	else
		ft_strdel(&line);
}

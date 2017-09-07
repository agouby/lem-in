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

t_list	*push_in_list(char *content)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		ft_memerr();
	new->content = content;
	new->next = NULL;
	return (new);
}

void	del_file(void *content, size_t size)
{
	(void)size;
	ft_strdel((char **)&content);
}

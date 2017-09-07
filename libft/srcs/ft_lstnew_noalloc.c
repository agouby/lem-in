/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_noalloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 12:57:56 by agouby            #+#    #+#             */
/*   Updated: 2017/09/07 16:06:05 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_noalloc(void *content)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	new->content = content;
	new->next = NULL;
	return (new);
}

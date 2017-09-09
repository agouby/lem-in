/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:11:58 by agouby            #+#    #+#             */
/*   Updated: 2017/09/09 11:57:42 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_file(t_env lem)
{
	lem.file = ft_lstrev(lem.file);
	ft_printf("PRINTING FILE : \n\n");
	while (lem.file)
	{
		ft_printf("%s\n", lem.file->content);
		lem.file = lem.file->next;
	}
}

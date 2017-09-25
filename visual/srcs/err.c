/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:49:46 by agouby            #+#    #+#             */
/*   Updated: 2017/09/25 21:20:18 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	check_for_error(t_env *v)
{
	if (v->file == NULL || ft_strequ(v->file->content, "ERROR"))
	{
		ft_printf("Error. Make sure you set the flag ");
		ft_printf("and check for errors in the terminal.\n");
		ft_lstdel(&v->file, del_file);
		exit(1);
	}
}

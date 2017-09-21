/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:49:46 by agouby            #+#    #+#             */
/*   Updated: 2017/09/21 21:21:31 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	check_for_error(t_env *v)
{
	if (ft_strequ(v->file->content, "NOVIS"))
	{
		ft_printf("No visualizer I quit.\n");
		exit(0);
	}
	if (ft_strequ(v->file->content, "ERROR"))
		v->err = 1;
}

void	print_err(t_env *v)
{
	mlx_string_put(v->mlx.ptr, v->mlx.win, WIN_X / 2, WIN_Y / 2, 0xFFFFFF, "ERROR.");
}

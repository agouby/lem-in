/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 14:49:46 by agouby            #+#    #+#             */
/*   Updated: 2017/09/20 17:47:22 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	check_for_error(t_env *v, char *line)
{
	if (ft_strequ(line, "NOVIS"))
	{
		ft_strdel(&line);
		exit(0);
	}
	if (ft_strequ(line, "ERROR"))
		v->err = 1;
}

void	print_err(t_env *v)
{
	mlx_string_put(v->mlx.ptr, v->mlx.win, WIDTH / 2, HEIGHT / 2, 0xFFFFFF, "ERROR.");
}

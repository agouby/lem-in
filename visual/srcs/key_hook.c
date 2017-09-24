/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 16:44:17 by agouby            #+#    #+#             */
/*   Updated: 2017/09/20 16:48:16 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		key_hook(int key, t_env *v)
{
	if (key == K_ESC)
		exit(0);
	if (v->direct)
		return (0);
	else if (key == K_AR_L)
	{
		if (v->cur_shot == -1)
			return (0);
		v->cur_shot--;
		print_shot(v);
	}
	else if (key == K_AR_R)
	{
		if (v->cur_shot + 1 == (long)v->nb_shots)
			return (0);
		v->cur_shot++;
		print_shot(v);
	}
	return (0);
}

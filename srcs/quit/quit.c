/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:37:23 by agouby            #+#    #+#             */
/*   Updated: 2017/09/20 10:20:35 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	quit_parsing(t_env *lem)
{
	crit_err(lem, CERR_NOTUBE);
	del_hash(lem->hash);
	exit(1);
}

void	quit_path(t_env *lem)
{
	crit_err(lem, CERR_NOPATH);
	del_hash(lem->hash);
	exit(1);
}

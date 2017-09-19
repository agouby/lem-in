/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:28:45 by agouby            #+#    #+#             */
/*   Updated: 2017/09/07 21:03:48 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	read_and_delete(char *line, ssize_t gnl_ret)
{
	if (!gnl_ret)
		ft_strdel(&line);
	else
	{
		while (get_next_line(0, &line))
			ft_strdel(&line);
		ft_strdel(&line);
	}
}

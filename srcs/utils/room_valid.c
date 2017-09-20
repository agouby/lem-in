/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:20:57 by agouby            #+#    #+#             */
/*   Updated: 2017/09/20 10:24:32 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		valid_room_name(const char *line, int *err)
{
	if (*line == ' ' || *line == 'L')
	{
		*err = ERR_RNAME;
		return (0);
	}
	return (1);
}

char		valid_room_coords(const char *line, int *err)
{
	while (*line)
	{
		if (!ft_isspace(*line) && !ft_isdigit(*line))
		{
			*err = ERR_COORD;
			return (0);
		}
		line++;
	}
	return (1);
}

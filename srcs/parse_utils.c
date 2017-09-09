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

void	command_unknown(const char *line)
{
	ft_printf("Commande <%s> is unknown", line);
}

void	parse_error(t_parser *pars, char **line)
{
	ft_printf("parse error.\n");
	ft_strdel(line);
	pars->err = 1;
}

void	read_and_delete(char *line, ssize_t gnl_ret)
{
	if (!gnl_ret)
	{
		ft_strdel(&line);
		return ;
	}
	while (get_next_line(0, &line))
		ft_strdel(&line);
	ft_strdel(&line);
}

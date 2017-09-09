/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   critical_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 11:42:46 by agouby            #+#    #+#             */
/*   Updated: 2017/09/09 11:42:48 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ants_err(char **line, ssize_t gnl_ret)
{
	ft_strdel(line);
	read_and_delete(*line, gnl_ret);
	ft_print_error("No ants.\n");
}

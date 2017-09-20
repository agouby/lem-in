/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 17:16:23 by agouby            #+#    #+#             */
/*   Updated: 2017/09/21 00:37:41 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	get_coords(t_room *r, char **line)
{
	(*line)++;
	r->c.x = ft_atou(*line);
	while (ft_isdigit(**line))
		(*line)++;
	(*line)++;
	r->c.y = ft_atou(*line);
	while (ft_isdigit(**line))
		(*line)++;
	if (**line != '\0')
		(*line)++;
}
char	*get_room(t_env *v, char *line, t_room **r, size_t ser)
{
	char	*ptr;

	ptr = ft_strchr(line, ' ');
	*ptr = '\0';
	*r = (t_room *)malloc(sizeof(t_room));
	(*r)->name = ft_strdup(line);
	*ptr = ' ';
	ptr++;
	(*r)->c.x = ft_atou(ptr);
	while (ft_isdigit(*ptr))
		ptr++;
	ptr++;
	(*r)->c.y = ft_atou(ptr);
	if (ser == 0)
		v->s = *r;
	else if (ser == 1)
		v->e = *r;
	while (ft_isdigit(*ptr))
		ptr++;
	return ((*ptr) ? ptr + 1 : NULL);
}

void	get_solution(t_env *v, char *line)
{
	(void)v;
	(void)line;
}

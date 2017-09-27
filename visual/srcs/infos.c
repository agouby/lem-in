/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 18:34:18 by agouby            #+#    #+#             */
/*   Updated: 2017/09/26 16:32:48 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	check_first_line(t_env *v)
{
	if (!ft_strisdigit(v->file->content))
	{
		ft_lstdel(&v->file, del_file);
		ft_print_error("File is corrupted.\n");
	}
}

void	check_solution(t_env *v, t_list *tmp)
{
	if (!tmp)
	{
		del_mlx(v);
		ft_print_error("File is corrupted.\n");
	}
}

void	get_infos(t_env *v)
{
	t_list	*tmp;

	check_first_line(v);
	tmp = v->file;
	v->nb_ants = ft_atou(tmp->content);
	tmp = tmp->next;
	get_limits(v, tmp->content);
	tmp = tmp->next;
	get_start_and_end(v, tmp->content);
	tmp = tmp->next;
	start_mlx(v);
	print_back(v);
	while (tmp && !ft_strequ(tmp->content, "SOLUTION"))
	{
		get_connexions(v, tmp->content);
		tmp = tmp->next;
	}
	check_solution(v, tmp);
	tmp = tmp->next;
	print_map(v);
	v->nb_shots = ft_lstlen(tmp);
	get_sol_tab(v, tmp);
	print_inf(v);
	print_shot(v);
}

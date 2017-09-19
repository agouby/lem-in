#include "lem_in.h"

void	go_throught_paths(t_env *lem, size_t *start_ants, size_t *ants_id_pick)
{
	t_path	*paths_tmp;
	t_rlist	*lst_tmp;

	(void)start_ants;
	(void)ants_id_pick;
	paths_tmp = lem->paths;
	while (paths_tmp)
	{
		lst_tmp = paths_tmp->lst;
		while (lst_tmp->next)
		{
			if (lst_tmp->r->ant_id == 0)
			lst_tmp = lst_tmp->next;
		}
		paths_tmp = paths_tmp->next;
	}
}

void	travel_ants(t_env *lem)
{
	size_t	start_ants;
	size_t	ants_id_pick;

	int i = 0;

	ants_id_pick = 1;
	start_ants = lem->ants_nb;
//	while (lem->end->r->ant_id != lem->ants_nb)
	while (i < 1)
	{
		go_throught_paths(lem, &start_ants, &ants_id_pick);
		i++;
	}
}

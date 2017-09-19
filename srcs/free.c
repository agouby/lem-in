#include "lem_in.h"

void	del_hash(t_rlist **hash)
{
	t_rlist	*tmp;
	t_rlist	*tmp_nei;
	unsigned int i;

	i = 0;
	while (i < H_SIZE)
	{
		if (hash[i])
		{
			while (hash[i])
			{
				tmp = hash[i];
				hash[i] = hash[i]->next;
				while (tmp->r->nei)
				{
					tmp_nei = tmp->r->nei;
					tmp->r->nei = tmp->r->nei->next;
					free(tmp_nei);
				}
				free(tmp->r->name);
				free(tmp->r);
				free(tmp);
			}
		}
		i++;
	}
	free(hash);
}

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

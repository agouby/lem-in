#include "lem_in.h"

void	rlist_add(t_rlist **old, t_rlist *new)
{
	new->next = *old;
	*old = new;
}

t_rlist	*rlist_new(t_room r)
{
	t_rlist *new;

	new = (t_rlist *)malloc(sizeof(t_rlist));
	new->r = r;
	new->next = NULL;
	return (new);
}


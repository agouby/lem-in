#include "lem_in.h"

void	path_add(t_path **old, t_path *new)
{
	new->next = *old;
	*old = new;
}

t_path	*path_new(t_rlist *lst)
{
	t_path *new;

	new = (t_path *)malloc(sizeof(t_path));
	new->lst = lst;
	return (new);
}

t_path	*path_rev(t_path *path)
{
	t_path *new;
	t_path *elem;

	new = NULL;
	while (path)
	{
		elem = path;
		path = path->next;
		elem->next = new;
		new = elem;
	}
	return (new);
}

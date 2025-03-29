#include "push_swap.h"

void	cleanlst(t_ilist *lst)
{
	t_ilist	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}
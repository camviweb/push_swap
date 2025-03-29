#include "push_swap.h"

t_ilist	*lstnew(int content)
{
	t_ilist	*node;

	node = malloc(sizeof(t_ilist));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	lstadd_front(t_ilist **lst, t_ilist *new)
{
	new->next = *lst;
	*lst = new;
}

t_ilist	*lstlast(t_ilist *lst)
{
	t_ilist *tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	lstadd_back(t_ilist **lst, t_ilist *new)
{
    t_ilist	*last;

	last = lstlast(*lst);
	if (!last)
		*lst = new;
    else
	    last->next = new;
}

int	lstsize(t_ilist *lst)
{
	t_ilist *tmp;
	unsigned int i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
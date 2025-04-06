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

long	max_lst(t_ilist *a)
{
	t_ilist	*tmp;
	long	max;
	tmp = a;
	max = a->content;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

long	min_lst(t_ilist *a)
{
	t_ilist	*tmp;
	long	min;

	tmp = a;
	min = a->content;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int pos_in_b(t_ilist *b, int n)
{
	int pos = 0;
	t_ilist *tmp = b;

	if (!b)
		return (0);

	if (n > max_lst(b) || n < min_lst(b))
		return (max_pos(b));

	while (tmp && tmp->next)
	{
		if (tmp->content > n && tmp->next->content < n)
			return (pos + 1);
		pos++;
		tmp = tmp->next;
	}
	return (0);
}

t_lists *rotateb_to_pos(t_lists *stacks, int pos)
{
	int size = lstsize(stacks->b);
	if (pos <= size / 2)
		while (pos-- > 0)
			stacks = rotateb(stacks);
	else
		while (pos++ < size)
			stacks = reverserotateb(stacks);
	return (stacks);
}


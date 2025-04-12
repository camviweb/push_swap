#include "push_swap.h"

t_lists	*rotatea_to_pos(t_lists *stacks, int pos)
{
	int	size;

	size = lstsize(stacks->a);
	if (pos <= size / 2)
		while (pos-- > 0)
			stacks = rotatea(stacks);
	else
		while (pos++ < size)
			stacks = reverserotatea(stacks);
	return (stacks);
}

t_lists	*rotate_to_poss(t_lists *stacks, int pos, int posa)
{
	int	count;
	int	comm;
	int	sizea;
	int	sizeb;

	sizea = lstsize(stacks->a);
	sizeb = lstsize(stacks->b);
	count = 0;
	comm = pos;
	if (posa < comm)
		comm = posa;
	if (pos <= sizeb / 2 && posa <= sizea / 2)
	{
		pos = pos - comm;
		posa = posa - comm;
		while (count++ < comm)
			stacks = rr(stacks);
	}
	else if (pos > sizeb / 2 && posa > sizea / 2){
		pos = pos - comm;
		posa = posa - comm;
		while (count++ < comm)
			stacks = rrr(stacks);
	}
	
	if (pos != 0)
		stacks = rotateb_to_pos(stacks, pos);
	else if (posa != 0)
		stacks = rotatea_to_pos(stacks, posa);
	return (stacks);
}

t_lists	*turkish_sort(t_lists *stacks)
{
	t_ilist	*tmp;
	int		pos;

	while (lstsize(stacks->a) > 0)
	{
		tmp = stacks->a;
		pos = pos_in_b(stacks->b, tmp->content);
		stacks = rotateb_to_pos(stacks, pos);
		stacks = pushb(stacks);
	}
	stacks = rotateb_to_max(stacks);
	while (lstsize(stacks->b) > 0)
		stacks = pusha(stacks);
	return (stacks);
}
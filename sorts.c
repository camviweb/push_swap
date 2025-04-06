#include "push_swap.h"

// how many is small ?
t_lists	*easy_sort(t_lists *stacks)
{
	if (lstsize(stacks->a) == 2)
	{
		if (stacks->a->content > stacks->a->next->content)
			// juste swapa(stacks) ? -> void
			stacks = swapa(stacks);
	}
	else if (lstsize(stacks->a) == 3)
		stacks = sort3(stacks);
	else if (lstsize(stacks->a) == 4)
		stacks = sort4(stacks);
	else
		stacks = sort5(stacks);
	return (stacks);
}

t_lists	*sort3(t_lists *stacks)
{
	return (pusha(stacks));
}

t_lists	*sort4(t_lists *stacks)
{
	return (pushb(stacks));
}

t_lists	*sort5(t_lists *stacks)
{
	return (rotatea(stacks));
}

t_lists	*turkish_sort(t_lists *stacks)
{
	t_ilist *current;
	int pos;

	while (lstsize(stacks->a) > 0)
	{
		current = stacks->a;
		pos = pos_in_b(stacks->b, current->content);
		stacks = rotateb_to_pos(stacks, pos);
		stacks = pushb(stacks);
	}
	stacks = rotateb_to_max(stacks);
	while (lstsize(stacks->b) > 0)
		stacks = pusha(stacks);

	return (stacks);
	// return (reverserotatea(stacks));
}
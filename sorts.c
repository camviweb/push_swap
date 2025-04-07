/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:37:24 by canguyen          #+#    #+#             */
/*   Updated: 2025/04/07 11:37:27 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*easy_sort(t_lists *stacks)
{
	if (lstsize(stacks->a) == 2)
	{
		if (stacks->a->content > stacks->a->next->content)
			stacks = swapa(stacks);
	}
	else if (lstsize(stacks->a) == 3)
		stacks = sort3(stacks);
	else if (lstsize(stacks->a) == 4)
		stacks = sort4(stacks);
	// else
	// 	stacks = sort5(stacks);
	return (stacks);
}

t_lists	*sort3(t_lists *stacks)
{
	if (is_sorted(stacks))
		return (stacks);
	return (pusha(stacks));
}

t_lists	*sort4(t_lists *stacks)
{
	if (is_sorted(stacks))
		return (stacks);
	return (pushb(stacks));
}

// t_lists	*sort5(t_lists *stacks)
// {
// 	if (is_sorted(stacks))
// 		return (stacks);
// 	return (rotatea(stacks));
// }

t_lists	*turkish_sort(t_lists *stacks)
{
	t_ilist	*max;
	int		pos;
	int		posa;

	while (lstsize(stacks->a) > 0)
	{
		max = max_node(stacks->a);
		posa = get_pos(stacks->a, max->content);
		pos = pos_in_b(stacks->b, get_value(stacks->a, posa));
		stacks = rotate_to_poss(stacks, pos, posa);
		// stacks = rotateb_to_pos(stacks, pos);
		// stacks = rotatea_to_pos(stacks, posa);
		stacks = pushb(stacks);
	}
	stacks = rotateb_to_max(stacks);
	while (lstsize(stacks->b) > 0)
		stacks = pusha(stacks);
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

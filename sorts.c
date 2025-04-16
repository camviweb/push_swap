/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:37:24 by canguyen          #+#    #+#             */
/*   Updated: 2025/04/12 13:59:28 by canguyen         ###   ########.fr       */
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
	else
		stacks = sort5(stacks);
	return (stacks);
}

t_lists	*sort3(t_lists *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->a->content;
	b = stacks->a->next->content;
	c = stacks->a->next->next->content;
	if (is_sorted(stacks))
		return (stacks);
	else if (b < a && a < c)
		stacks = swapa(stacks);
	else if (c < a && a < b)
		stacks = reverserotatea(stacks);
	else if (b < c && c < a)
		stacks = rotatea(stacks);
	else if (a < c && c < b)
		stacks = swapa(reverserotatea(stacks));
	else if (c < b && b < a)
		stacks = reverserotatea(swapa(stacks));
	return (stacks);
}

t_lists	*sort4(t_lists *stacks)
{
	if (is_sorted(stacks))
		return (stacks);
	stacks = rotate_to_a_min(stacks);
	stacks = pushb(stacks);
	stacks = sort3(stacks);
	stacks = pusha(stacks);
	return (stacks);
}

t_lists	*sort5(t_lists *stacks)
{
	if (is_sorted(stacks))
		return (stacks);
	stacks = rotate_to_a_min(stacks);
	stacks = pushb(stacks);
	stacks = sort4(stacks);
	stacks = pusha(stacks);
	return (stacks);
}

t_lists	*radix_sort(t_lists *stacks)
{
	int	size;
	int	i;
	int	j;
	int	max_bits;

	if (is_sorted(stacks))
		return (stacks);
	size = lstsize(stacks->a);
	max_bits = find_max_bits(stacks);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((stacks->a)->content >> i) & 1) == 0)
				stacks = pushb(stacks);
			else
				stacks = rotatea(stacks);
			j++;
		}
		while (lstsize(stacks->b) > 0)
			stacks = pusha(stacks);
		i++;
	}
	return (stacks);
}

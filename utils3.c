/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:28:30 by canguyen          #+#    #+#             */
/*   Updated: 2025/04/12 13:56:48 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*rotate_to_a_min(t_lists *stacks)
{
	int	min_pos;

	min_pos = get_pos(stacks->a, min_lst(stacks->a));
	if (min_pos < lstsize(stacks->a) / 2)
	{
		while (stacks->a->content != min_lst(stacks->a))
			stacks = rotatea(stacks);
	}
	else
	{
		while (stacks->a->content != min_lst(stacks->a))
			stacks = reverserotatea(stacks);
	}
	return (stacks);
}

int	is_sorted(t_lists *stacks)
{
	int		size;
	int		i;
	t_ilist	*tmp;

	tmp = stacks->a;
	size = lstsize(tmp);
	i = 0;
	while (i < size - 1)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

int	find_max_bits(t_lists *stacks)
{
	int	size;
	int	max;
	int	max_bits;

	max_bits = 0;
	size = lstsize(stacks->a);
	max = size - 1;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

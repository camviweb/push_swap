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

t_lists	*radix_sort(t_lists *stacks)
{
	int	size;
	int	i;
	int	j;
	int max_bits;
	int max;

	max_bits = 0;
	i = 0;
	size = lstsize(stacks->a);
	max = size - 1;
	ft_printf("max : %d\n", max);
	while ((max >> max_bits) != 0)
		max_bits++;
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
	ft_printf("max : %d\n", max);
	return (stacks);
}

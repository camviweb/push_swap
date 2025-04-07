/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:37:35 by canguyen          #+#    #+#             */
/*   Updated: 2025/04/07 11:37:37 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
t_lists	*swapa(t_lists *stacks)
{
	write(1, "sa\n", 3);
	stacks->count++;
	stacks->a = lstswap(stacks->a);
	return (stacks);
}

t_lists	*swapb(t_lists *stacks)
{
	write(1, "sb\n", 3);
	stacks->count++;
	stacks->b = lstswap(stacks->b);
	return (stacks);
}

t_lists	*ss(t_lists *stacks)
{
	write(1, "ss\n", 3);
	stacks->count += 2;
	stacks->a = lstswap(stacks->a);
	stacks->b = lstswap(stacks->b);
	return (stacks);
}

t_ilist	*lstswap(t_ilist *one)
{
	t_ilist *tmp;
	t_ilist *two;

	if (!one)
		return (NULL);
	tmp = one;
	two = one->next;
	one = two;
	tmp->next = two->next;
	one->next = tmp;
	return (one);
}

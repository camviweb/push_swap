/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:37:06 by canguyen          #+#    #+#             */
/*   Updated: 2025/04/07 11:37:08 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*reverserotatea(t_lists *stacks)
{
	write(1, "rra\n", 4);
	stacks->count++;
	stacks->a = lstreverserotate(stacks->a);
	return (stacks);
}

t_lists	*reverserotateb(t_lists *stacks)
{
	write(1, "rrb\n", 4);
	stacks->count++;
	stacks->b = lstreverserotate(stacks->b);
	return (stacks);
}

t_lists	*rrr(t_lists *stacks)
{
	write(1, "rrr\n", 4);
	stacks->count += 2;
	stacks->a = lstreverserotate(stacks->a);
	stacks->b = lstreverserotate(stacks->b);
	return (stacks);
}

t_ilist	*lstreverserotate(t_ilist *lst)
{
	t_ilist	*last;
	t_ilist	*penultimate;
	t_ilist	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next)
	{
		penultimate = current;
		current = current->next;
	}
	penultimate->next = NULL;
	last = current;
	last->next = lst;
	lst = last;
	return (lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:31:03 by canguyen          #+#    #+#             */
/*   Updated: 2025/04/07 11:31:06 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*pusha(t_lists *stacks)
{
	write(1, "pa\n", 3);
	stacks->count++;
	return (lstpusha(stacks));
}

t_lists	*pushb(t_lists *stacks)
{
	write(1, "pb\n", 3);
	stacks->count++;
	return (lstpushb(stacks));
}

t_lists	*lstpusha(t_lists *stacks)
{
	t_ilist	*tmp;

	if (!stacks->b)
		return (stacks);
	if (!stacks->a)
		stacks->a = lstnew(stacks->b->content);
	else
		lstadd_front(&stacks->a, lstnew(stacks->b->content));
	tmp = stacks->b->next;
	free(stacks->b);
	stacks->b = tmp;
	// if (ps_lstsize(stacks->b) > 0)
	// 	stacks->b->prev = NULL;
	return (stacks);
}

t_lists	*lstpushb(t_lists *stacks)
{
	t_ilist	*tmp;

	if (!stacks->a)
		return (stacks);
	if (!stacks->b)
		stacks->b = lstnew(stacks->a->content);
	else
		lstadd_front(&stacks->b, lstnew(stacks->a->content));
	tmp = stacks->a->next;
	free(stacks->a);
	stacks->a = tmp;
	// if (ps_lstsize(stacks->b) > 0)
	// 	stacks->b->prev = NULL;
	return (stacks);
}

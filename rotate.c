/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:37:14 by canguyen          #+#    #+#             */
/*   Updated: 2025/04/07 11:37:17 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*rotatea(t_lists *stacks)
{
	write(1, "ra\n", 3);
	stacks->count++;
	stacks->a = lstrotate(stacks->a);
	return (stacks);
}

t_lists	*rotateb(t_lists *stacks)
{
	write(1, "rb\n", 3);
	stacks->count++;
	stacks->b = lstrotate(stacks->b);
	return (stacks);
}

t_lists	*rr(t_lists *stacks)
{
	write(1, "rr\n", 3);
	stacks->count += 2;
	stacks->a = lstrotate(stacks->a);
	stacks->b = lstrotate(stacks->b);
	return (stacks);
}

t_ilist	*lstrotate(t_ilist *lst)
{
	t_ilist	*two;
	t_ilist	*last;

	if (!lst)
		return (NULL);
	last = lstlast(lst);
	two = lst->next;
	lst->next = NULL;
	last->next = lst;
	lst = two;
	return (lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:28:23 by canguyen          #+#    #+#             */
/*   Updated: 2025/04/07 11:28:26 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleanlst(t_ilist *lst)
{
	t_ilist	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

int	max_lst(t_ilist *lst)
{
	t_ilist	*tmp;
	int		max;

	tmp = lst;
	max = lst->content;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	min_lst(t_ilist *lst)
{
	t_ilist	*tmp;
	int		min;

	tmp = lst;
	min = lst->content;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	pos_in_b(t_ilist *b, int n)
{
	int		pos;
	t_ilist	*tmp;

	pos = 0;
	tmp = b;
	if (!b)
		return (0);
	if (n > max_lst(b) || n < min_lst(b))
		return (max_pos(b));
	while (tmp && tmp->next)
	{
		if (tmp->content > n && tmp->next->content < n)
			return (pos + 1);
		pos++;
		tmp = tmp->next;
	}
	return (0);
}

t_lists	*rotateb_to_pos(t_lists *stacks, int pos)
{
	int	size;

	size = lstsize(stacks->b);
	if (pos <= size / 2)
		while (pos-- > 0)
			stacks = rotateb(stacks);
	else
		while (pos++ < size)
			stacks = reverserotateb(stacks);
	return (stacks);
}

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

t_ilist *max_node(t_ilist *lst)
{
	t_ilist *max;
	t_ilist *tmp;
	
	max = lst;
	tmp = lst;
	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return max;
}

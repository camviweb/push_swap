/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:28:30 by canguyen          #+#    #+#             */
/*   Updated: 2025/04/07 11:28:33 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lists	*rotateb_to_max(t_lists *stacks)
{
	stacks = rotateb_to_pos(stacks, max_pos(stacks->b));
	return (stacks);
}

int	max_pos(t_ilist *b)
{
	int	max;
	int	pos;

	max = max_lst(b);
	pos = 0;
	while (get_value(b, pos) != max)
	{
		pos++;
	}
	return (pos);
}

int	get_value(t_ilist *b, int pos)
{
	int		i;
	t_ilist	*tmp;

	i = 0;
	tmp = b;
	while (i < pos)
	{
		i++;
		tmp = tmp->next;
	}
	return (tmp->content);
}

int	get_pos(t_ilist *lst, int val)
{
	int	i;
	t_ilist *tmp;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		if (tmp->content == val)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
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

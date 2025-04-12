/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:28:23 by canguyen          #+#    #+#             */
/*   Updated: 2025/04/12 13:36:38 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_ilist	*min_node(t_ilist *a)
{
	t_ilist	*tmp;
	t_ilist	*min_node;
	long	min;

	tmp = a;
	min = a->content;
	min_node = tmp;
	while (tmp)
	{
		if (tmp->content < min)
		{
			min_node = tmp;
			min = tmp->content;
		}
		tmp = tmp->next;
	}
	return (min_node);
}

t_ilist	*max_node(t_ilist *a)
{
	t_ilist	*tmp;
	t_ilist	*max_node;
	long	max;

	tmp = a;
	max = a->content;
	max_node = tmp;
	while (tmp)
	{
		if (tmp->content > max)
		{
			max_node = tmp;
			max = tmp->content;
		}
		tmp = tmp->next;
	}
	return (max_node);
}

int	get_pos(t_ilist *lst, int val)
{
	t_ilist	*tmp;
	int		i;

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

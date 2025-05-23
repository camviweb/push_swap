/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:37:42 by canguyen          #+#    #+#             */
/*   Updated: 2025/04/07 11:37:48 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish(t_lists *stacks)
{
	free(stacks);
	write(2, "Error\n", 6);
	// mandatory ?
	exit(1);
}

void	lstprint(t_ilist *lst)
{
	t_ilist	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_printf("%d ", tmp->content);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

int	is_number(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int	doublon(t_ilist *a, int nb)
{
	t_ilist	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->content == nb)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:28:40 by canguyen          #+#    #+#             */
/*   Updated: 2025/04/12 13:34:57 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_lists	*stacks;

	stacks = malloc(sizeof(t_lists));
	if (stacks == NULL)
		return (1);
	if (argc == 1)
		finish(stacks);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stacks = parse(stacks, argc, argv);
	stacks = sort(stacks);
	cleanlst(stacks->a);
	cleanlst(stacks->b);
	free(stacks);
	return (0);
}

t_lists	*parse(t_lists *stacks, int argc, char **argv)
{
	int			i;
	long long	tmp;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			finish(stacks);
		tmp = ft_atol(argv[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			finish(stacks);
		if (doublon(stacks->a, tmp))
			finish(stacks);
		if (!stacks->a)
			stacks->a = lstnew(tmp);
		else
			lstadd_back(&stacks->a, lstnew(tmp));
		i++;
	}
	return (stacks);
}

t_lists	*sort(t_lists *stacks)
{
	int	len;

	len = lstsize(stacks->a);
	if (len <= 5)
		stacks = easy_sort(stacks);
	else
	{
		stacks = radix_sort(normalize(stacks));
	}
	return (stacks);
}

t_lists	*normalize(t_lists *stacks)
{
	int		i;
	int		size;
	t_ilist	*min;
	t_ilist	*max;

	i = 0;
	size = lstsize(stacks->a);
	while (i < size)
	{
		min = min_node(stacks->a);
		min->content = 2147483647 - i;
		i++;
	}
	i = 0;
	while (i < size)
	{
		max = max_node(stacks->a);
		max->content = i;
		i++;
	}
	return (stacks);
}

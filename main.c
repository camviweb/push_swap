/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:28:40 by canguyen          #+#    #+#             */
/*   Updated: 2025/04/07 11:28:42 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// a enlever
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_lists	*stacks;

	// pourquoi 2 et pas 3 ?
	stacks = malloc(sizeof(t_lists));
	// to check
	if (stacks == NULL)
		return (1);
	if (argc == 1)
		finish(stacks);
	if (argc == 2)
		// probablement cast en 'const char'
		argv = ft_split(argv[1], ' ');
	stacks = parse(stacks, argc, argv);
	// ft_printf("parse : ");
	// lstprint(stacks->a);
	stacks = normalize(stacks);
	// ft_printf("normalisé : ");
	// lstprint(stacks->a);
	stacks = sort(stacks);
	// ft_printf("sorte a : ");
	// lstprint(stacks->a);
	// ft_printf("sorte b : ");
	// lstprint(stacks->b);
	ft_printf("%d coups\n", stacks->count);
	free(stacks);
	return (0);
}

t_lists	*parse(t_lists *stacks, int argc, char **argv)
{
	int			i;
	// changer
	long long	tmp;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			finish(stacks);
		tmp = ft_atol(argv[i]);
		// printf("nb : %ld\n", tmp);
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
	if (len <= 4)
		stacks = easy_sort(stacks);
	else
		stacks = radix_sort(stacks);
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
		// ft_printf("node min : %i\n", min->content);
		min->content = 	2147483647 - (1 + i);
		i++;
	}
	// ft_printf("step 1 : ");
	// lstprint(stacks->a);
	i = 0;
	while (i < size)
	{
		max = max_node(stacks->a);
		max->content = i;
		i++;
	}
	return (stacks);
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

t_lists *chunked_radix_sort(t_lists *stacks)
{
    int chunk_size = 10;  // Taille du chunk (à ajuster en fonction de la taille de ta pile)
    int len = lstsize(stacks->a);
    int num_chunks = len / chunk_size;
    if (len % chunk_size != 0)
        num_chunks++;  // Ajouter un dernier chunk si la pile n'est pas un multiple de la taille du chunk
    
    t_lists *chunks[num_chunks];
    
    // Diviser la pile en chunks
    t_ilist *tmp = stacks->a;
    for (int i = 0; i < num_chunks; i++)
    {
        chunks[i] = malloc(sizeof(t_lists)); // Allouer de la mémoire pour chaque chunk
        chunks[i]->a = NULL;
        chunks[i]->b = NULL;
        
        for (int j = 0; j < chunk_size && tmp != NULL; j++)
        {
            // Ajouter à chaque chunk
            lstadd_back(&chunks[i]->a, lstnew(tmp->content));
            tmp = tmp->next;
        }
    }

    // Appliquer radix sort sur chaque chunk
    for (int i = 0; i < num_chunks; i++)
    {
		chunks[i] = normalize(chunks[i]);
        chunks[i] = radix_sort(chunks[i]);  // Appliquer radix_sort à chaque chunk
    }

    // Rassembler les chunks triés dans la pile principale
    for (int i = 0; i < num_chunks; i++)
    {
        while (chunks[i]->a != NULL)
        {
            stacks = pusha(stacks);  // Rassembler dans la pile principale
        }
        free(chunks[i]);  // Libérer chaque chunk
    }

    return stacks;
}

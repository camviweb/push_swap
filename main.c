#include "push_swap.h"
// a enlever
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_lists	*stacks;

	// pourquoi 2 et pas 3 ?
	stacks = malloc(2 * sizeof(t_ilist));
	// to check
	if (stacks == NULL)
		return (0);
	if (argc == 1)
		finish(stacks);
	if (argc == 2)
		// probablement cast en 'const char'
		argv = ft_split(argv[1], ' ');
	stacks = parse(stacks, argc, argv);
	ft_printf("parse : ");
	lstprint(stacks->a);
	write (1, "\n", 1);
	stacks = sort(stacks);
	ft_printf("sorte a : ");
	lstprint(stacks->a);
	write (1, "\n", 1);
	ft_printf("sorte b : ");
	lstprint(stacks->b);
	write (1, "\n", 1);
	free(stacks);
	return (0);
}

t_lists	*parse(t_lists *stacks, int argc, char **argv)
{
	int	i;
	long	tmp;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			finish(stacks);
		tmp = ft_atol(argv[i]);
		printf("nb : %ld\n", tmp);
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
		stacks = turkish_sort(stacks);
	return (stacks);
}

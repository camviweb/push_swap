#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// int	main(void)
// {
// 	int	value;
//     t_list *node;

// 	value = 42;
// 	node = ft_lstnew(&value);
// 	ft_printf("Valeur stockée : %d\n", *(int *)(node->content));
// 	free(node);
// 	return (0);
// }

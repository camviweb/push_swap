#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int main(void){
    t_list *lst;
    t_list *new;
    int a;
    int b;

    a = 1;
    b = 2;
    lst = ft_lstnew(&a);
    new = ft_lstnew(&b);
    ft_lstadd_front(&lst, new);
    ft_printf("Premiere valeur: %d\n", *(int *)lst->content);
    ft_printf("Deuxieme valeur: %d\n", *(int *)(lst->next)->content);
}
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_ilist
{
	int				content;
	struct s_ilist	*next;
}					t_ilist;

typedef struct s_lists
{
	t_ilist			*a;
	t_ilist			*b;
	size_t			count;
}					t_lists;

// main
t_lists				*parse(t_lists *stacks, int argc, char **argv);
t_lists				*sort(t_lists *stacks);

// sorts
t_lists				*easy_sort(t_lists *stacks);
t_lists				*sort3(t_lists *stacks);
t_lists				*sort4(t_lists *stacks);
t_lists				*sort5(t_lists *stacks);
t_lists				*turkish_sort(t_lists *stacks);

// utils
void				finish(t_lists *stacks);
int					is_number(char *s);
void				lstprint(t_ilist *lst);
int					doublon(t_ilist *a, int nb);

// listes chainees
t_ilist				*lstnew(int content);
void				lstadd_front(t_ilist **lst, t_ilist *new);
int					lstsize(t_ilist *lst);
t_ilist				*lstlast(t_ilist *lst);
void				lstadd_back(t_ilist **lst, t_ilist *new);
void				cleanlst(t_ilist *lst);
// void	ft_lstdelone(t_list *lst, void (*del)(void *));
// void	ft_lstclear(t_list **lst, void (*del)(void *));
// void	ft_lstiter(t_list *lst, void (*f)(void *));
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

// instructions
t_lists				*swapa(t_lists *stacks);
t_lists				*swapb(t_lists *stacks);
t_lists				*ss(t_lists *stacks);
t_ilist				*lstswap(t_ilist *one);
t_lists				*pusha(t_lists *stacks);
t_lists				*pushb(t_lists *stacks);
t_lists				*lstpusha(t_lists *stacks);
t_lists				*lstpushb(t_lists *stacks);
t_lists				*rotatea(t_lists *stacks);
t_lists				*rotateb(t_lists *stacks);
t_lists				*rr(t_lists *stacks);
t_ilist				*lstrotate(t_ilist *lst);
t_lists				*reverserotatea(t_lists *stacks);
t_lists				*reverserotateb(t_lists *stacks);
t_lists				*rrr(t_lists *stacks);
t_ilist				*lstreverserotate(t_ilist *lst);

#endif

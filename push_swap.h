/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canguyen <canguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:34:21 by canguyen          #+#    #+#             */
/*   Updated: 2025/04/07 11:34:31 by canguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
// keep ?
# include <limits.h>

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
t_lists				*normalize(t_lists *stacks);

// sorts
t_lists				*easy_sort(t_lists *stacks);
t_lists				*sort3(t_lists *stacks);
t_lists				*sort4(t_lists *stacks);
// t_lists				*sort5(t_lists *stacks);
t_lists				*radix_sort(t_lists *stacks);
t_lists				*chunked_radix_sort(t_lists *stacks);

// utils
void				finish(t_lists *stacks);
int					is_number(char *s);
void				lstprint(t_ilist *lst);
int					doublon(t_ilist *a, int nb);
t_ilist				*min_node(t_ilist *a);
t_ilist				*max_node(t_ilist *a);

// listes chainees
t_ilist				*lstnew(int content);
void				lstadd_front(t_ilist **lst, t_ilist *new);
int					lstsize(t_ilist *lst);
t_ilist				*lstlast(t_ilist *lst);
void				lstadd_back(t_ilist **lst, t_ilist *new);
void				cleanlst(t_ilist *lst);
int					max_lst(t_ilist *b);
int					min_lst(t_ilist *b);
int					pos_in_b(t_ilist *b, int n);
t_lists				*rotateb_to_pos(t_lists *stacks, int pos);
t_lists				*rotateb_to_max(t_lists *stacks);
int					max_pos(t_ilist *b);
int					get_value(t_ilist *b, int pos);
int					is_sorted(t_lists *stacks);
// t_ilist				*max_node(t_ilist *lst);
int					get_pos(t_ilist *lst, int val);
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

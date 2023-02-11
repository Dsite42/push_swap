/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:45:02 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/11 17:19:56 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include <strings.h>
# include <stdlib.h>
# include "libft/libft.h"
//# include <stddef.h>
//# include <unistd.h>

typedef struct s_psw_list
{
	int					content;
	int					index;

	int 				costs;
	int					ra;
	int					rra;
	int					rb;
	int					rrb;
	int					rr;
	int					rrr;
	struct s_psw_list	*node_b;

	struct s_psw_list	*next;
}						t_psw_list;



t_psw_list	*psw_lstnew(int content);
t_psw_list	*psw_lstlast(t_psw_list *lst);
t_psw_list	*create_list(char **argv);
int	psw_lstsize(t_psw_list *lst);
void	psw_lstadd_back(t_psw_list **lst, t_psw_list *new);
void	psw_lstadd_front(t_psw_list **lst, t_psw_list *new);

void	sa(t_psw_list *a_list);
void	pb(t_psw_list **a_list, t_psw_list **b_list);
void	ra(t_psw_list **a_list, t_psw_list **b_list);
void	rra(t_psw_list **a_list, t_psw_list **b_list);
void	rb(t_psw_list **a_list, t_psw_list **b_list);
void	rrb(t_psw_list **a_list, t_psw_list **b_list);
void	rr(t_psw_list **a_list, t_psw_list **b_list);
void	rrr(t_psw_list **a_list, t_psw_list **b_list);
#endif
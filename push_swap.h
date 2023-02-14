/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:45:02 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/14 19:43:17 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

typedef struct s_psw_list
{
	int					content;
	int					index;

	int					costs;
	int					ra;
	int					rra;
	int					rb;
	int					rrb;
	int					rr;
	int					rrr;
	struct s_psw_list	*node_b;

	struct s_psw_list	*next;
}						t_psw_list;

//Operations functions:
void		sa(t_psw_list *a_list);
void		pa(t_psw_list **a_list, t_psw_list **b_list);
void		pb(t_psw_list **a_list, t_psw_list **b_list);
void		ra(t_psw_list **a_list, t_psw_list **b_list);
void		rra(t_psw_list **a_list, t_psw_list **b_list);
void		rb(t_psw_list **a_list, t_psw_list **b_list);
void		rrb(t_psw_list **a_list, t_psw_list **b_list);
void		rr(t_psw_list **a_list, t_psw_list **b_list);
void		rrr(t_psw_list **a_list, t_psw_list **b_list);
void		run_rotate(t_psw_list **a_list, t_psw_list **b_list,
				int amount_rotate, void (*f)(t_psw_list **, t_psw_list **));
void		rotate_all(t_psw_list **a_list, t_psw_list **b_list,
				t_psw_list *node_a_to_push);
void		sort_three(t_psw_list **a_list);
void		swap_all_to_a(t_psw_list **a_list, t_psw_list **b_list);
void		rotate_to_min(t_psw_list **a_list, t_psw_list **b_list);
void		psw_lstadd_back(t_psw_list **lst, t_psw_list *new);
void		psw_lstadd_front(t_psw_list **lst, t_psw_list *new);

//Helper functions:
int			calc_single_index(t_psw_list *a_list, int to_find);
void		clear_node_cost_values(t_psw_list *lst);
void		copy_node_cost_values(t_psw_list *lst, t_psw_list *new_values);
void		clear_stack_values(t_psw_list *lst);
void		rr_cost_optimization(t_psw_list *a_list, t_psw_list *b_list);
void		rrr_cost_optimization(t_psw_list *a_list, t_psw_list *b_list,
				t_psw_list *a_list_start);
void		rx_rrx_costs(t_psw_list *a_list, t_psw_list *b_list);
void		update_lists(t_psw_list *a_list, t_psw_list *b_list);
void		error(t_psw_list *a_list);
int			is_duplicate(t_psw_list *a_list, int nbr_to_check);
void		seed_to_next_nbr(char **str);
int			is_sorted(t_psw_list *lst);

//List functions:
t_psw_list	*create_lst(char **argv, int argc);
t_psw_list	*psw_lstnew(int content);
t_psw_list	*psw_lstlast(t_psw_list *lst);
t_psw_list	*create_lst_from_args(char **argv, int argc);
t_psw_list	*create_lst_from_str(char *str, int argc);
int			psw_lstsize(t_psw_list *lst);
t_psw_list	*cheapest_node(t_psw_list *a_list, t_psw_list *b_list);
t_psw_list	*find_node_a(int content_b, t_psw_list *a_list);
t_psw_list	*find_node_b(int content_a, t_psw_list *b_list);
void		psw_lstclear(t_psw_list **lst);
void		psw_lstdelone(t_psw_list *lst);

//void		print_stacks(t_psw_list *a_list, t_psw_list *b_list);
#endif
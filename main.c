/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:03:32 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/23 10:40:10 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_stacks(t_psw_list **a_list, t_psw_list **b_list)
{
	psw_lstclear(a_list);
	psw_lstclear(b_list);
}

void	initialize_input(t_psw_list **a_list, int argc, char **argv)
{
	if (argc < 2)
		exit(0);
	if (argc == 2)
		*a_list = create_lst_from_str(*(argv + 1));
	else
		*a_list = create_lst_from_args(argv + 1, argc);
}

void	handle_just_three(t_psw_list *a_list, t_psw_list *b_list)
{
	if (psw_lstsize(a_list) <= 3)
	{
		update_lists(a_list, b_list);
		if (is_sorted(a_list) == 0)
			sort_three(&a_list);
		psw_lstclear(&a_list);
		exit(0);
	}
}

void	input_already_sorted(t_psw_list *a_list)
{
	if (is_sorted(a_list) == 1)
	{
		psw_lstclear(&a_list);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_psw_list	*a_list;
	t_psw_list	*b_list;
	t_psw_list	*node_a_to_push;

	b_list = NULL;
	initialize_input(&a_list, argc, argv);
	input_already_sorted(a_list);
	handle_just_three(a_list, b_list);
	pb(&a_list, &b_list);
	pb(&a_list, &b_list);
	while (psw_lstsize(a_list) > 3)
	{
		update_lists(a_list, b_list);
		node_a_to_push = cheapest_node(a_list, b_list);
		rotate_all(&a_list, &b_list, node_a_to_push);
		pb(&a_list, &b_list);
		clear_stack_values(a_list);
		clear_stack_values(b_list);
	}
	update_lists(a_list, b_list);
	if (is_sorted(a_list) == 0)
		sort_three(&a_list);
	swap_all_to_a(&a_list, &b_list);
	rotate_to_min(&a_list, &b_list);
	clear_stacks(&a_list, &b_list);
}

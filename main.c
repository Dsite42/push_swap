/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:03:32 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/12 22:54:06 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_psw_list	*a_list;
	t_psw_list	*b_list;
	t_psw_list	*node_a_to_push;

	a_list = create_lst(argv + 1);
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
	sort_three(&a_list);
	swap_all_to_a(&a_list, &b_list);
	rotate_to_min(&a_list, &b_list);
}


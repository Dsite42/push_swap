/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:03:32 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/13 15:24:56 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/*
void	print_stacks(t_psw_list *a_list, t_psw_list *b_list)
{
	printf("STACK A:\n");
	while (a_list != NULL)
	{
		printf("%i index:%i costs:%i ra:%i rra:%i rb:%i rrb:%i rr:%i rrr:%i\n",
			a_list->content, a_list->index, a_list->costs, a_list->ra,
				a_list->rra, a_list->rb, a_list->rrb, a_list->rr, a_list->rrr);
		a_list = a_list->next;
	}

	printf("STACK B:\n");
	while (b_list != NULL)
	{
		printf("%i index:%i costs:%i ra:%i rra:%i rb:%i rrb:%i rr:%i rrr:%i\n",
			b_list->content, b_list->index, b_list->costs, b_list->ra,
				b_list->rra, b_list->rb, b_list->rrb, b_list->rr, b_list->rrr);
		b_list = b_list->next;
	}
}
*/

int	main(int argc, char **argv)
{
	t_psw_list	*a_list;
	t_psw_list	*b_list;
	t_psw_list	*node_a_to_push;

	if (argc < 2)
		return (0);
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
	psw_lstclear(&a_list);
	psw_lstclear(&b_list);
}
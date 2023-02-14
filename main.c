/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:03:32 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/14 19:38:16 by cgodecke         ###   ########.fr       */
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


void	print_stack(t_psw_list *a_list)
{
	while (a_list != NULL)
	{
		printf("A:%i\n", a_list->content);
		a_list = a_list->next;
	}

}
*/

void	initialize_input(t_psw_list **a_list, int argc, char **argv)
{
	if (argc < 2)
		exit(0);
	if (argc == 2)
		*a_list = create_lst_from_str(*(argv + 1), argc);
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

int	main(int argc, char **argv)
{
	t_psw_list	*a_list;
	t_psw_list	*b_list;
	t_psw_list	*node_a_to_push;

	initialize_input(&a_list, argc, argv);
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
	psw_lstclear(&a_list);
	psw_lstclear(&b_list);
}

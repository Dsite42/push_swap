/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:03:32 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/20 17:59:00 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bonus/push_swap_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include "get_next_line/get_next_line_bonus.h"

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

/*
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
	char		*operations_str;
	char		*new_input;

	initialize_input(&a_list, argc, argv);
	//b_list = NULL;
	operations_str = (char *) malloc(sizeof(char));
	if (operations_str == NULL)
		return (0);
	new_input = get_next_line(0);
	input_already_sorted(a_list, b_list, new_input);
	operations_str = psw_strjoin_free(operations_str, new_input);
	while (new_input != NULL)
	{
		new_input = get_next_line(0);
		if (new_input != NULL)
			operations_str = psw_strjoin_free(operations_str, new_input);
	}
	while (*operations_str != '\0')
	{
		run_operation_bonus(&a_list, &b_list, &operations_str);
	}
	check_result(a_list, b_list);
}

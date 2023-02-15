/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:03:32 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/15 17:43:58 by cgodecke         ###   ########.fr       */
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

char	*seed_to_next_operation(char *str)
{
	while (*str != '\n' && *str != '\0')
	{
		str++;
	}
	if (*str == '\n')
		str++;
	return (str);
}

void	run_operation(t_psw_list **a_list, t_psw_list **b_list,
			char **operations_str)
{
	update_lists(*a_list, *b_list);
	if (ft_strncmp("rra", *operations_str, 3) == 0)
		rra_bonus(a_list, b_list);
	else if (ft_strncmp("rrb", *operations_str, 3) == 0)
		rrb_bonus(a_list, b_list);
	else if (ft_strncmp("rrr", *operations_str, 3) == 0)
		rrr_bonus(a_list, b_list);
	else if (ft_strncmp("pa", *operations_str, 2) == 0)
		pa_bonus(a_list, b_list);
	else if (ft_strncmp("pb", *operations_str, 2) == 0)
		pb_bonus(a_list, b_list);
	else if (ft_strncmp("ra", *operations_str, 2) == 0)
		ra_bonus(a_list, b_list);
	else if (ft_strncmp("rb", *operations_str, 2) == 0)
		rb_bonus(a_list, b_list);
	else if (ft_strncmp("rr", *operations_str, 2) == 0)
		rr_bonus(a_list, b_list);
	else if (ft_strncmp("sa", *operations_str, 2) == 0)
		sa_bonus(*a_list, *b_list);
	else if (ft_strncmp("sb", *operations_str, 2) == 0)
		sb_bonus(*a_list, *b_list);
	else
		error(*a_list, *b_list);
	*operations_str = seed_to_next_operation(*operations_str);
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
		run_operation(&a_list, &b_list, &operations_str);
	}
	check_result(a_list, b_list);
}

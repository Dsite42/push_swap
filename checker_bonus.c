/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:03:32 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/23 13:16:52 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "bonus/push_swap_bonus.h"
#include "get_next_line/get_next_line_bonus.h"

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

void	no_operations_input(t_psw_list *a_list)
{
	if (is_sorted(a_list))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	psw_lstclear(&a_list);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_psw_list	*a_list;
	t_psw_list	*b_list;
	char		*operations_str;
	char		*new_input;

	initialize_input(&a_list, argc, argv);
	b_list = NULL;
	operations_str = (char *) malloc(sizeof(char));
	if (operations_str == NULL)
		return (0);
	new_input = get_next_line(0);
	if (new_input == NULL)
		no_operations_input(a_list);
	operations_str = psw_strjoin_free(operations_str, new_input);
	while (new_input != NULL)
	{
		new_input = get_next_line(0);
		if (new_input != NULL)
			operations_str = psw_strjoin_free(operations_str, new_input);
	}
	while (*operations_str != '\0')
		run_operation_bonus(&a_list, &b_list, &operations_str);
	check_result(a_list, b_list);
}

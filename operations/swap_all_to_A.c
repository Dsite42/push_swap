/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_all_to_A.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:20:32 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 22:48:16 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_all_to_a(t_psw_list **a_list, t_psw_list **b_list)
{
	int			rotate_amount;
	t_psw_list	*insert_before;

	while (*b_list != NULL)
	{
		insert_before = find_node_a((*b_list)->content, *a_list);
		rotate_amount = calc_single_index(*a_list, insert_before->content) - 1;
		if (rotate_amount <= (psw_lstsize(*a_list) - rotate_amount))
			run_rotate(a_list, b_list, rotate_amount, &ra);
		else
		{
			rotate_amount = psw_lstsize(*a_list) - rotate_amount;
			run_rotate(a_list, b_list, rotate_amount, &rra);
		}
		pa(a_list, b_list);
	}
}

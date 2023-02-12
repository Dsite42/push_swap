/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:25:07 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 21:25:31 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_to_min(t_psw_list **a_list, t_psw_list **b_list)
{
	int			min_min_content;
	int			rotate_amount;
	t_psw_list	*min_min_node;
	t_psw_list	*a_list_start;

	a_list_start = *a_list;
	min_min_content = INT_MAX;
	while (*a_list != NULL)
	{
		if ((*a_list)->content < min_min_content)
		{
			min_min_content = (*a_list)->content;
			min_min_node = *a_list;
		}
		*a_list = (*a_list)->next;
	}
	*a_list = a_list_start;
	rotate_amount = calc_single_index(*a_list, min_min_node->content) - 1;
	if (rotate_amount <= (psw_lstsize(*a_list) - rotate_amount))
		run_rotate(a_list, b_list, rotate_amount, &ra);
	else
	{
		rotate_amount = psw_lstsize(*a_list) - rotate_amount;
		run_rotate(a_list, b_list, rotate_amount, &rra);
	}
}

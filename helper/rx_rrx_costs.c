/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx_rrx_costs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:14:44 by chris             #+#    #+#             */
/*   Updated: 2023/02/21 14:21:53 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rx_rrx_costs(t_psw_list *a_list, t_psw_list *b_list)
{
	t_psw_list	*a_list_start;

	a_list_start = a_list;
	while (a_list != NULL)
	{
		if (a_list->index - 1
			<= (psw_lstsize(a_list_start) - a_list->index + 1))
			a_list->ra = a_list->index - 1;
		else
			a_list->rra = psw_lstsize(a_list_start) - a_list->index + 1;
		if (a_list->node_b->index - 1
			< (psw_lstsize(b_list) - a_list->node_b->index + 1))
			a_list->rb = a_list->node_b->index - 1;
		else
			a_list->rrb = psw_lstsize(b_list) - a_list->node_b->index + 1;
		a_list->costs = a_list->ra + a_list->rra + a_list->rb
			+ a_list->rrb + a_list->rr + a_list->rrr;
		rr_cost_optimization(a_list);
		rrr_cost_optimization(a_list, b_list, a_list_start);
		a_list = a_list->next;
	}
}

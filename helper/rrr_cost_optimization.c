/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_cost_optimization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:13:31 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 22:47:00 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr_cost_optimization(t_psw_list *a_list, t_psw_list *b_list,
	t_psw_list *a_list_start)
{
	t_psw_list	*new_costs;

	new_costs = psw_lstnew(a_list->content);
	clear_node_cost_values(new_costs);
	if ((psw_lstsize(a_list_start) - a_list->index + 1)
		> (psw_lstsize(b_list) - a_list->node_b->index + 1))
	{
		new_costs->costs = (psw_lstsize(a_list_start) - a_list->index + 1);
		new_costs->rrr = (psw_lstsize(b_list) - a_list->node_b->index + 1);
		new_costs->rra = new_costs->costs - new_costs->rrr;
	}
	else
	{
		new_costs->costs = (psw_lstsize(b_list) - a_list->node_b->index + 1);
		new_costs->rrr = (psw_lstsize(a_list_start) - a_list->index + 1);
		new_costs->rrb = new_costs->costs - new_costs->rrr;
	}
	if (new_costs->costs < a_list->costs)
		copy_node_cost_values(a_list, new_costs);
	free(new_costs);
}

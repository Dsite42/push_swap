/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_cost_optimization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:12:48 by chris             #+#    #+#             */
/*   Updated: 2023/02/13 20:37:06 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr_cost_optimization(t_psw_list *a_list, t_psw_list *b_list)
{
	t_psw_list	*new_costs;

	new_costs = psw_lstnew(a_list->content);
	clear_node_cost_values(new_costs);
	if (a_list->index - 1 > a_list->node_b->index - 1)
	{
		new_costs->costs = a_list->index - 1;
		new_costs->rr = a_list->node_b->index - 1;
		new_costs->ra = new_costs->costs - new_costs->rr;
	}
	else
	{
		new_costs->costs = a_list->node_b->index - 1;
		new_costs->rr = a_list->index - 1;
		new_costs->rb = new_costs->costs - new_costs->rr;
	}
	if (new_costs->costs < a_list->costs)
		copy_node_cost_values(a_list, new_costs);
	free(new_costs);
}

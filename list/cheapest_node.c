/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:15:25 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 22:15:43 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_psw_list	*cheapest_node(t_psw_list *a_list, t_psw_list *b_list)
{
	t_psw_list	*cheapest;
	int			min_costs;

	rx_rrx_costs(a_list, b_list);
	min_costs = a_list->costs;
	cheapest = a_list;
	while (a_list != NULL)
	{
		if (a_list->costs < min_costs)
		{
			min_costs = a_list->costs;
			cheapest = a_list;
		}
		a_list = a_list->next;
	}
	return (cheapest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_node_cost_values.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:10:22 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 22:10:46 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	copy_node_cost_values(t_psw_list *lst, t_psw_list *new_values)
{
		lst->costs = new_values->costs;
		lst->ra = new_values->ra;
		lst->rra = new_values->rra;
		lst->rb = new_values->rb;
		lst->rrb = new_values->rrb;
		lst->rr = new_values->rr;
		lst->rrr = new_values->rrr;
}

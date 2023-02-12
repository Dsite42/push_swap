/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_node_cost_values.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:09:42 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 22:10:02 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clear_node_cost_values(t_psw_list *lst)
{
		lst->costs = 0;
		lst->ra = 0;
		lst->rra = 0;
		lst->rb = 0;
		lst->rrb = 0;
		lst->rr = 0;
		lst->rrr = 0;
}

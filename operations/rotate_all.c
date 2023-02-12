/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:14:47 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 22:48:42 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_all(t_psw_list **a_list, t_psw_list **b_list,
	t_psw_list *node_a_to_push)
{
	run_rotate(a_list, b_list, node_a_to_push->ra, &ra);
	run_rotate(a_list, b_list, node_a_to_push->rra, &rra);
	run_rotate(a_list, b_list, node_a_to_push->rb, &rb);
	run_rotate(a_list, b_list, node_a_to_push->rrb, &rrb);
	run_rotate(a_list, b_list, node_a_to_push->rr, &rr);
	run_rotate(a_list, b_list, node_a_to_push->rrr, &rrr);
}

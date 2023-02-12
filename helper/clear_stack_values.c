/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_stack_values.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:11:15 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 22:11:34 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	clear_stack_values(t_psw_list *lst)
{
	while (lst != NULL)
	{
		clear_node_cost_values(lst);
		lst->node_b = NULL;
		lst = lst->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:15:48 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/12 11:23:04 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb(t_psw_list **a_list, t_psw_list **b_list)
{
	t_psw_list	*new_last_node;
	t_psw_list	*b_list_start;
	int			index_new_last_node;

	b_list_start = *b_list;
	index_new_last_node = psw_lstsize(b_list_start) - 1;
	while (b_list_start != NULL)
	{
		if (b_list_start->index == index_new_last_node)
			new_last_node = b_list_start;
		b_list_start = b_list_start->next;
	}
	psw_lstadd_front(b_list, psw_lstlast(*b_list));
	new_last_node->next = NULL;
	write(1, "rrb\n", 4);
}
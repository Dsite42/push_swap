/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:15:48 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/15 17:42:28 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra_bonus(t_psw_list **a_list, t_psw_list **b_list)
{
	t_psw_list	*new_last_node;
	t_psw_list	*a_list_start;
	int			index_new_last_node;

	if (psw_lstsize(*a_list) < 2)
		error(*a_list, *b_list);
	a_list_start = *a_list;
	index_new_last_node = psw_lstsize(a_list_start) - 1;
	while (a_list_start != NULL)
	{
		if (a_list_start->index == index_new_last_node)
			new_last_node = a_list_start;
		a_list_start = a_list_start->next;
	}
	psw_lstadd_front(a_list, psw_lstlast(*a_list));
	new_last_node->next = NULL;
}

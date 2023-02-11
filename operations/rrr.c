/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:15:48 by cgodecke          #+#    #+#             */
/*   Updated: 2023/02/11 14:43:15 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_psw_list **a_list, t_psw_list **b_list)
{
	t_psw_list	*new_last_node;
	t_psw_list	*list_start;
	int			index_new_last_node;

	list_start = *a_list;
	index_new_last_node = psw_lstsize(list_start) - 1;
	while (list_start != NULL)
	{
		if (list_start->index == index_new_last_node)
			new_last_node = list_start;
		list_start = list_start->next;
	}
	psw_lstadd_front(a_list, psw_lstlast(*a_list));
	new_last_node->next = NULL;
	list_start = *b_list;
	index_new_last_node = psw_lstsize(list_start) - 1;
	while (list_start != NULL)
	{
		if (list_start->index == index_new_last_node)
			new_last_node = list_start;
		list_start = list_start->next;
	}
	psw_lstadd_front(b_list, psw_lstlast(*b_list));
	new_last_node->next = NULL;
	write(1, "rrr\n", 4);
}

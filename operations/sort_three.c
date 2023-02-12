/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:19:21 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 21:19:49 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_psw_list **a_list)
{
	int			max_max_content;
	t_psw_list	*max_max_node;
	t_psw_list	*a_list_start;

	a_list_start = *a_list;
	while (*a_list != NULL)
	{
		if ((*a_list)->content > max_max_content)
		{
			max_max_content = (*a_list)->content;
			max_max_node = *a_list;
		}
		*a_list = (*a_list)->next;
	}
	*a_list = a_list_start;
	if (max_max_node->index == 3
		&& (*a_list)->content < (*a_list)->next->content)
		return ;
	if (max_max_node->index == 1)
		ra(a_list, NULL);
	if (max_max_node->index == 2)
		rra(a_list, NULL);
	if ((*a_list)->content > (*a_list)->next->content)
		sa(*a_list);
}

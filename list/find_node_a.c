/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_node_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:07:37 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 22:07:58 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_psw_list	*find_node_a(int content_b, t_psw_list *a_list)
{
	int			min_content;
	int			min_min_content;
	t_psw_list	*min_node;
	t_psw_list	*min_min_node;

	min_content = INT_MAX;
	min_min_content = INT_MAX;
	while (a_list != NULL)
	{
		if (a_list->content < min_min_content)
		{
			min_min_content = a_list->content;
			min_min_node = a_list;
		}
		if (a_list->content > content_b && a_list->content < min_content)
		{
			min_content = a_list->content;
			min_node = a_list;
		}
		a_list = a_list->next;
	}
	if (min_content == INT_MAX)
		return (min_min_node);
	return (min_node);
}

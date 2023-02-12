/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_node_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:08:42 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 22:09:00 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_psw_list	*find_node_b(int content_a, t_psw_list *b_list)
{
	int			max_content;
	int			max_max_content;
	t_psw_list	*max_node;
	t_psw_list	*max_max_node;

	max_content = 0;
	max_max_content = 0;
	while (b_list != NULL)
	{
		if (b_list->content > max_max_content)
		{
			max_max_content = b_list->content;
			max_max_node = b_list;
		}
		if (b_list->content < content_a && b_list->content > max_content)
		{
			max_content = b_list->content;
			max_node = b_list;
		}
		b_list = b_list->next;
	}
	if (max_content == 0)
		return (max_max_node);
	return (max_node);
}

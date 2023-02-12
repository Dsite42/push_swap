/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 22:12:01 by chris             #+#    #+#             */
/*   Updated: 2023/02/12 22:46:43 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	update_lists(t_psw_list *a_list, t_psw_list *b_list)
{
	int		i;

	i = 1;
	while (a_list != NULL)
	{
		a_list->index = i;
		a_list->node_b = find_node_b(a_list->content, b_list);
		a_list = a_list->next;
		i++;
	}
	i = 1;
	while (b_list != NULL)
	{
		b_list->index = i;
		b_list = b_list->next;
		i++;
	}
}
